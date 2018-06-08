#ifndef POOLGAME_H
#define POOLGAME_H

#include <vector>
#include <QPainter>
#include <QSize>
#include "math.h"
#include <QMediaPlayer>

#include "table.h"
#include "ball.h"
#include "changeinpoolgame.h"
#include "gamestats.h"

#include "caretaker.h"
#include "originator.h"

/**
 * @brief The PoolGame class runs the pool game, it is in charge of the physics of the pool game as well as
 * drawing the game
 */
class PoolGame
{
public:
    /**
     * @brief PoolGame constructor
     * @param m_table a pointer to a Table object, Poolgame takes ownership of this pointer
     * @param balls a vector of pointers to balls, Poolgame takes ownership of all the contained pointers
     */
    PoolGame(Table * m_table,std::vector<Ball*> balls)
        :m_table(m_table),m_balls(balls)
    {
        stats = new GameStats();
        cueBall = true;
        ballSounds = new QMediaPlayer();
        ballSounds->setMedia(QUrl("qrc:/sounds/BallCollision.wav"));
        ballSounds->setVolume(60);
        caretaker = new Caretaker();
        originator = new Originator();
        //setting up the original ones
        originator->setState(m_balls);
        caretaker->update(originator->saveToMemento());
    }

    ~PoolGame();

    std::vector<Ball *> getBalls() const{
        return m_balls;
    }

    /**
     * @brief simulate one timestep of the game
     * @param timeStep is the period of time that this timestep is simulating
     */
    void simulateTimeStep(float timeStep);

    /**
     * @brief redoMove - Activated when the player decides to undo the last play
     */
    void undoMove();

    /**
     * @brief takeSnapshot - Updates the memento for the game.
     * Will be activated everytime after the user releases the cueball for the shot.
     */
    void takeSnapshot();

    /**
     * @brief draws all elements of the game, table and balls in that order
     * @param p is the painter which is used to paint the object
     */
    void draw(QPainter &p);

    /**
     * @brief size
     * @return the size of the game
     */
    QSize size() const {return QSize(m_table->width(),m_table->height());}

    /**
     * @brief getCueball
     * @return if the CueBall is available
     */
    bool getCueball() const {return cueBall;}


    GameStats* getStats() {return stats;}
    /**
     * @brief makeCueBallAvailable - Gives the player the CueBall so they can
     * interact with and continue playing
     */
    void makeCueBallAvailable(){cueBall = true;}

private:
    /**
     * @brief collide two balls if they are in contact
     * @param b1
     * @param b2
     * @return the change in the pool game after the collision
     */
    ChangeInPoolGame collide(Ball *b1, Ball *b2);

    GameStats * stats;
    Table * m_table;
    std::vector<Ball*> m_balls;
    bool cueBall;
    QMediaPlayer * ballSounds;
    Caretaker* caretaker;
    Originator* originator;
    QVector2D prevPos;
};

#endif // POOLGAME_H
