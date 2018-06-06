#include "statistics.h"
#include "QDebug"


Statistics::Statistics(Dialog *parent):
//    m_pocketStats(pocketStats),
    m_popUp(QString::fromLatin1("play for some stats"),parent,Qt::SplashScreen | Qt::WindowStaysOnTopHint)
{
    /* Connect dialog signals to Statistics slots
     * So that its notified when keyboard is used
    */
    connect(parent,&Dialog::keyPressed,this,&Statistics::keyPressed);
    connect(parent,&Dialog::keyReleased,this,&Statistics::keyReleased);

    //Setting up the variable pointers
    setUpPopUp();
//    setUpPointers(game);
}


float Statistics::getAccuracy()
{
    // HITS OVER TOTAL
    float accuracy = 0.00;
    if(!m_accuracy->isNull()){
    float total = m_accuracy->x() + m_accuracy->y();
    float hits = m_accuracy->x();
       accuracy = hits/total;
    }


    return accuracy;
}

QString Statistics::statsToString()
{
    float accuracy = this->getAccuracy();
    QString returningString;
    returningString.append("****Stats****\n");
    returningString.append("Accuracy: ");
    returningString.append(QString::number(accuracy));
    returningString.append("%\n");
    return returningString;
}

void Statistics::keyPressed(QKeyEvent *event)
{

    if(event->key() == Qt::Key_S)
    {
        m_popUp.setText(statsToString());
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
//    m_popUp.show();
}

void Statistics::setUpPointers(PoolGame * game)
{
    this->m_accuracy = game->getStats()->getAccuracy();
}
