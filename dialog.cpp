#include "dialog.h"

#include <QPainter>
#include <QSize>
#include "QDebug"
constexpr float fps = 60;
constexpr float timeStep = 0.01;

Dialog::Dialog(QWidget *parent)
    :QDialog(parent),m_game(nullptr),m_framerateTimer(new QTimer()),m_timestepTimer(new QTimer())
//      stat(this)
{}

void Dialog::start(PoolGame *game)
{
    m_game = game;
    this->setMinimumSize(m_game->size());
    this->resize(m_game->size());
    connect(m_framerateTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(m_timestepTimer,SIGNAL(timeout()),this,SLOT(runSimulationStep()));
    m_framerateTimer->start(1000/fps);
    m_timestepTimer->start(1000*timeStep);
//    stat->
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if(m_game)
        m_game->draw(p);
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    qDebug()<< "in here mouse";
    emit mousePressed(event);
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMoved(event);
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    emit mouseReleased(event);
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< "in here";
    emit keyPressed(event);
}

void Dialog::keyReleaseEvent(QKeyEvent *event)
{
    emit keyReleased(event);
}

Dialog::~Dialog()
{
    delete m_game;
    delete m_framerateTimer;
    delete m_timestepTimer;
}

void Dialog::runSimulationStep()
{
    if(m_game)
    {
        if(m_game->getCueball())
        {
            m_game->simulateTimeStep(timeStep);
        }else
        {
            //Emits a signal to place the cue ball. before continuing the game
           emit placeCueBall(m_game->size());
            m_game->makeCueBallAvailable();
        }
    }
}
