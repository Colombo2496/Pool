#include "cueballdecorator.h"
#include <QDebug>
CueBallDecorator::CueBallDecorator(Ball *b, Dialog *parent)
    :BallDecorator(b),clicked(false),placeCue(false),
      popup(QString::fromLatin1("Lets play!"),parent,Qt::SplashScreen | Qt::WindowStaysOnTopHint)
{
    setUpPopUp();
    //connect dialog signals to cueball slots so that this class is notified when the mouse is used
    connect(parent,&Dialog::mousePressed,this,&CueBallDecorator::mousePressed);
    connect(parent,&Dialog::mouseMoved,this,&CueBallDecorator::mouseMoved);
    connect(parent,&Dialog::mouseReleased,this,&CueBallDecorator::mouseReleased);
    connect(parent,&Dialog::placeCueBall,this,&CueBallDecorator::placeCueBall);
    hitCueSound.setMedia(QUrl("qrc:/sounds/CueballHit.wav"));
    hitCueSound.setVolume(50);
    connect(parent,&Dialog::keyPressed,this,&CueBallDecorator::keyPressed);
    connect(parent,&Dialog::keyReleased,this,&CueBallDecorator::keyReleased);
}

void CueBallDecorator::draw(QPainter &p)
{
    //Check for ball velocity here. When it's zero just replace the current memento with the new one
//    if(m_ball->velocity() == QVector2D(0,0)){
//        savedData
//    }
    m_ball->draw(p);
    if(clicked)
        p.drawLine(mousePos.toPointF(),m_ball->position().toPointF());
}

void CueBallDecorator::showPopup(bool wrongPlacement)
{
    //placing it not behind the baulk line
    if(wrongPlacement){
        popup.setText("**To Place Cue Ball**\n"
                      "Click inside the 'Baulk' zone.\n"
                      "The left hand side rectangle");
    }else{
        popup.setText("**To Place Cue Ball**\n"
                      "Click on the desired position in-between:\n"
                      "1. The 'baulk' line\n "
                      "2. The left edge of the Table");
    }

    popup.show();
    QTimer::singleShot(5000, &popup, &QLabel::hide);
}


void CueBallDecorator::mousePressed(QMouseEvent *event)
{
    if(velocity().lengthSquared()<0.001 && (QVector2D(event->pos())-position()).length() < radius() && !placeCue)
    {
        clicked = true;
        placeCue = false;
        mousePos = QVector2D(event->pos());
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
        if(this->mousePos.x()<= baulkZone.rwidth() &&
                this->mousePos.y()  <= baulkZone.rheight())
        {
            placeCue = false;
            //sets the position of the last time it was used
            setPosition(mousePos);
        }else
        {
            showPopup(true);
        }
    }else if(clicked)
    {
        clicked = false;
        setVelocity(4*(m_ball->position()-mousePos));
        if(hitCueSound.state() == QMediaPlayer::PlayingState){
            hitCueSound.setPosition(0);
        }else if(hitCueSound.state() == QMediaPlayer::StoppedState){
            hitCueSound.play();
        }
    }
}

void CueBallDecorator::placeCueBall(QSize tableDimensions)
{
    placeCue = true;
    if(baulkZone.isEmpty()){
        baulkZone = tableDimensions;
        baulkZone.setWidth((baulkZone.rheight())/2);
    }
    showPopup(false);
}

void CueBallDecorator::setUpPopUp()
{
    QPalette qPalette = popup.palette();
    qPalette.setBrush(QPalette::Background, QColor(0xff, 0xe0, 0xc0));
    popup.setPalette(qPalette);
    popup.setFrameStyle(QLabel::Raised | QLabel::Panel);
    popup.setAlignment(Qt::AlignCenter);
    popup.setFixedSize(320, 200);
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
//        //Use the memento here!
//        emit mementoTime();
        qDebug() << "Use the memento";
    }

}
