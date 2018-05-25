#ifndef MEMENTO_H
#define MEMENTO_H
//#include "changeinpoolgame.h"
#include "originator.h"
#include "ball.h"

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
    Memento(std::vector<Ball *> newState): state(newState){}

    ~Memento(){}

    /**
     * @brief getState - Get the current Memento
     * @return
     */
    std::vector<Ball *> getState(){return state;}

    friend class Originator;
    std::vector<Ball *> state = {};
};

#endif // MEMENTO_H
