#ifndef POOLGAME_H
#define POOLGAME_H

#include <vector>
#include <QPainter>
#include <QSize>
#include "math.h"

#include "table.h"
#include "ball.h"

#include "changeinpoolgame.h"

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
     * @brief draws all elements of the game, table and balls in that order
     * @param p is the painter which is used to paint the object
     */
    void draw(QPainter &p);

    /**
     * @brief size
     * @return the size of the game
     */
    QSize size(){return QSize(m_table->width(),m_table->height());}

private:
    /**
     * @brief collide two balls if they are in contact
     * @param b1
     * @param b2
     * @return the change in the pool game after the collision
     */
    ChangeInPoolGame collide(Ball *b1, Ball *b2);


    Table * m_table;
    std::vector<Ball*> m_balls;
    Caretaker* caretaker;
    Originator* originator;
    QVector2D prevPos;
};

#endif // POOLGAME_H
