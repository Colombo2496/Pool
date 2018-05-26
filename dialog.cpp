#include "dialog.h"

#include <QPainter>
#include <QSize>
#include <QDebug>
#include "cueballdecorator.h"

constexpr float fps = 60;
constexpr float timeStep = 0.01;

Dialog::Dialog(QWidget *parent)
    :QDialog(parent),m_game(nullptr),m_framerateTimer(new QTimer()),m_timestepTimer(new QTimer())
{
//    CueBallDecorator* cueBall;
//    connect(cueBall,&CueBallDecorator::keyReleased,this,&Dialog::restoreMove);
//      connect(&a)
}

void Dialog::start(PoolGame *game)
{
    m_game = game;
    this->setMinimumSize(m_game->size());
    this->resize(m_game->size());
    connect(m_framerateTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(m_timestepTimer,SIGNAL(timeout()),this,SLOT(runSimulationStep()));
    m_framerateTimer->start(1000/fps);
    m_timestepTimer->start(1000*timeStep);
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if(m_game)
        m_game->draw(p);
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
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
    if(event->key() == Qt::Key_R){
        for(Ball* b : m_game->getBalls()){
            QString colour = b->colour().name();
            if(b->colour() == Qt::white &&
                    b->velocity() == QVector2D(0,0)){
                        m_keyPressed = true;
                        break; // To stop iterating
            }
        }

    }
//    emit keyPressed(event);
}

void Dialog::keyReleaseEvent(QKeyEvent *event)
{
    if(m_keyPressed){
        m_keyPressed = false;
        restoreMove();
    }
//    emit keyReleased(event);
}

void Dialog::restoreMove()
{
    m_game->undoMove();
    qDebug() << "finished move";
//    runSimulationStep();
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
        m_game->simulateTimeStep(timeStep);
}
