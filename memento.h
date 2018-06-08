#ifndef MEMENTO_H
#define MEMENTO_H
#include "ball.h"
//#include "stage2ball.h"
#include <QVector2D>

/**
 * @brief The Memento class
 * Stores the Positions of every single ball in the game.
 * Used for undoing the previous move of a shot. It can only be accessed when
 * the cue ball is stationary
 */
class Memento
{
    Memento(){}
    /**
     * @brief Memento - Create a new Memento constructor with new param
     * @param newState
     */
    Memento(std::vector<QVector2D> velocity, std::vector<QVector2D> position):
        m_velocity(velocity),
        m_position(position){}

    ~Memento(){delete this;}

    /**
     * @brief getState - Get the current Memento
     * @return
     */
    Memento* getState(){return this;}

    friend class Originator;
    std::vector<QVector2D> m_velocity;
    std::vector<QVector2D> m_position;
};

#endif // MEMENTO_H
