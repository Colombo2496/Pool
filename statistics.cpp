#include "statistics.h"



Statistics::Statistics(Dialog *parent,PoolGame game,std::vector<unsigned int*> pocketStats):
    m_pocketStats(pocketStats),
    m_popUp(QString::fromLatin1("play for some stats"),parent,Qt::SplashScreen | Qt::WindowStaysOnTopHint)
{
    /* Connect dialog signals to Statistics slots
     * So that its notified when keyboard is used
    */
    connect(parent,&Dialog::keyPressed,this,&Statistics::keyPressed);
    connect(parent,&Dialog::keyReleased,this,&Statistics::keyReleased);

    //Setting up the variable pointers
    setUpPopUp();
    setUpPointers(game);
}


float Statistics::getAccuracy()
{
    return 0.00;
}

void Statistics::keyPressed(QKeyEvent *event)
{
    if(event->key() == Qt::Key_S)
    {
        m_popUp.show();
    }
}

void Statistics::keyReleased(QKeyEvent *event)
{
    if(event->key() == Qt::Key_S)
        m_popUp.hide();
}

void Statistics::setUpPopUp()
{
    QPalette qPalette = m_popUp.palette();
    qPalette.setBrush(QPalette::Background, QColor(0xff, 0xe0, 0xc0));
    m_popUp.setPalette(qPalette);
    m_popUp.setFrameStyle(QLabel::Raised | QLabel::Panel);
    m_popUp.setAlignment(Qt::AlignCenter);
    m_popUp.setFixedSize(320, 200);
    m_popUp.show();
}

void Statistics::setUpPointers(PoolGame game)
{
    this->m_accuracy = game.getAccuracy();
}
