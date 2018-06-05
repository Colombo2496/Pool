#include "cueballdecorator.h"
#include <QDebug>
CueBallDecorator::CueBallDecorator(Ball *b, Dialog *parent)
    :BallDecorator(b),clicked(false),placeCue(false)
{
    //connect dialog signals to cueball slots so that this class is notified when the mouse is used
    connect(parent,&Dialog::mousePressed,this,&CueBallDecorator::mousePressed);
    connect(parent,&Dialog::mouseMoved,this,&CueBallDecorator::mouseMoved);
    connect(parent,&Dialog::mouseReleased,this,&CueBallDecorator::mouseReleased);
    connect(parent,&Dialog::placeCueBall,this,&CueBallDecorator::placeCueBall);
}

void CueBallDecorator::draw(QPainter &p)
{
    m_ball->draw(p);
    if(clicked)
        p.drawLine(mousePos.toPointF(),m_ball->position().toPointF());
}


void CueBallDecorator::mousePressed(QMouseEvent *event)
{
    if(velocity().lengthSquared()<0.001 && (QVector2D(event->pos())-position()).length() < radius())
    {
        clicked = true;
        mousePos = QVector2D(event->pos());
        placeCue = false;
    }else if(placeCue){
        mousePos = QVector2D(event->pos());
    }
}

void CueBallDecorator::mouseMoved(QMouseEvent *event)
{
    if(clicked)
    {
        mousePos = QVector2D(event->pos());
    }

}

void CueBallDecorator::mouseReleased(QMouseEvent *event)
{

    if(placeCue)
    {
        if(this->mousePos.x() /*+ this->radius()*/ <= baulkZone.rwidth() &&
                this->mousePos.y() /*+ this->radius()*/ <= baulkZone.rheight())
        {
            placeCue = false;
            //sets the position of the last time it was used
            setPosition(mousePos);
            qDebug() << "Set the cue Ball"; //must be a warning box
        }else
        {
            qDebug() << "must be inside the baulk";
            qDebug() << mousePos;
        }
    }else if(clicked)
    {
        clicked = false;
        setVelocity(4*(m_ball->position()-mousePos));
    }
}

void CueBallDecorator::placeCueBall(QSize tableDimensions)
{
    placeCue = true;
    baulkZone = tableDimensions;
    baulkZone.setWidth((baulkZone.rheight())/2);
     this->setColour(Qt::white);
//    this->setPosition(QVector2D(rand() % tableDimensions.rwidth(),rand() % tableDimensions.rheight()));
//    qDebug() << "in here!";
}
