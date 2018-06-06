#ifndef POOLGAME_H
#define POOLGAME_H

#include <vector>
#include <QPainter>
#include <QSize>
#include "math.h"

#include "table.h"
#include "ball.h"
#include "changeinpoolgame.h"
#include "gamestats.h"
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
    }

    ~PoolGame();

    /**
     * @brief simulate one timestep of the game
     * @param timeStep is the period of time that this timestep is simulating
     */
    void simulateTimeStep(float timeStep);

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
};

#endif // POOLGAME_H
