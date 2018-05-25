#include "cueballdecorator.h"
#include <QDebug>
CueBallDecorator::CueBallDecorator(Ball *b, Dialog *parent)
    :BallDecorator(b),clicked(false)
{
    //connect dialog signals to cueball slots so that this class is notified when the mouse is used
    connect(parent,&Dialog::mousePressed,this,&CueBallDecorator::mousePressed);
    connect(parent,&Dialog::mouseMoved,this,&CueBallDecorator::mouseMoved);
    connect(parent,&Dialog::mouseReleased,this,&CueBallDecorator::mouseReleased);
    connect(parent,&Dialog::keyPressed,this,&CueBallDecorator::keyPressed);
    connect(parent,&Dialog::keyReleased,this,&CueBallDecorator::keyReleased);
}

void CueBallDecorator::draw(QPainter &p)
{
    //Check for ball velocity here. When it's zero just replace the current memento with the new one

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
    if(clicked)
    {
        clicked = false;
        setVelocity(4*(m_ball->position()-mousePos));
    }
}

void CueBallDecorator::keyPressed(QKeyEvent *event)
{
    if(m_ball->velocity() == QVector2D(0,0) && event->key() == Qt::Key_R){
        m_keyPressed = true;
    }
}

void CueBallDecorator::keyReleased(QKeyEvent *event)
{
    if(m_keyPressed){
        m_keyPressed = false;
        //Use the memento here!
        qDebug() << "Use the memento";
    }
}
