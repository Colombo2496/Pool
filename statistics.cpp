#include "statistics.h"
#include "QDebug"


Statistics::Statistics(Dialog *parent):
    m_popUp(QString::fromLatin1("play for some stats"),parent,Qt::SplashScreen | Qt::WindowStaysOnTopHint)
{
    /* Connect dialog signals to Statistics slots
     * So that its notified when keyboard is used
    */
    connect(parent,&Dialog::keyPressed,this,&Statistics::keyPressed);
    connect(parent,&Dialog::keyReleased,this,&Statistics::keyReleased);

    //Setting up the variable pointers
    setUpPopUp();
}


const float Statistics::getAccuracy()
{
    // HITS OVER TOTAL
    float accuracy = 0.00;
    QVector2D* recordedAcc = this->ballStats->getAccuracy();
    if(!recordedAcc->isNull()){
    float total =  + recordedAcc->y();
    float hits = recordedAcc->x();
       accuracy = hits/total;
    }


    return accuracy;
}

QString Statistics::statsToString()
{
    float accuracy = this->getAccuracy();
    QString returningString;
    returningString.append("****Stats****\n");

//    //Accuracy
//    returningString.append("Accuracy: ");
//    returningString.append(QString::number(accuracy,'g',3));
//    returningString.append("%\n");

    //Times cue ball has sunk
    unsigned int ballSunk = *ballStats->getCueSinking();
    returningString.append("Times Cue was sunk: ");
    returningString.append(QString::number(ballSunk));
    returningString.append("\n");
    return returningString;
}

void Statistics::keyPressed(QKeyEvent *event)
{

    if(event->key() == Qt::Key_S)
    {
        //Check if the pointers have been assigned or not
        if(m_pocketStats == nullptr && ballStats != nullptr)
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
    this->ballStats = game->getStats();
}

void Statistics::setUpPocketPointers(vector<unsigned int *> *pocketStats)
{
    this->m_pocketStats = pocketStats;
}
