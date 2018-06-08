#include "dialog.h"

#include <QPainter>
#include <QSize>
#include <QDebug>
#include "cueballdecorator.h"

constexpr float fps = 60;
constexpr float timeStep = 0.01;

Dialog::Dialog(QWidget *parent)
    :QDialog(parent),m_game(nullptr),m_framerateTimer(new QTimer()),m_timestepTimer(new QTimer())
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
    ambientNoise = new QMediaPlayer();
    ambientNoise->setMedia(QUrl("qrc:/sounds/ambienceNoise.mp3"));
    ambientNoise->setVolume(45);
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

void Dialog::mouseDoubleClickEvent(QMouseEvent * event)
{
    MakeBallCommand command(m_game,QVector2D(event->pos()));
    command.execute();
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMoved(event);
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
        m_game->takeSnapshot();
    emit mouseReleased(event);

}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_R){
        m_keyPressed = true;
    }else if(event->key() == Qt::Key_M){
        stopMusic = !stopMusic;
    }
    emit keyPressed(event);
}

void Dialog::keyReleaseEvent(QKeyEvent *event)
{
    if(m_keyPressed){
        m_keyPressed = false;
        restoreMove();
    }
    emit keyReleased(event);
}

void Dialog::restoreMove()
{
    m_game->undoMove();
}



Dialog::~Dialog()
{
    delete m_game;
    delete m_framerateTimer;
    delete m_timestepTimer;
    delete ambientNoise;
}

void Dialog::runSimulationStep()
{
    if(m_game)
    {
        playMusic(stopMusic);
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

void Dialog::playMusic(bool stop)
{
    //Loop if reached the end of the music
    if(ambientNoise->state() == QMediaPlayer::EndOfMedia){
        //Rewind it back to the original starting point
        ambientNoise->setPosition(0);
    }

    if(stop){
        ambientNoise->pause();
    }else{
        ambientNoise->play();
    }
}
