#ifndef CARETAKER_H
#define CARETAKER_H
#include "memento.h"

/**
 * @brief The Caretaker class
 */
class Caretaker
{
public:
    ~Caretaker(){/*delete this->SavedState;*/}
    /**
     * @brief update - the current savedState of the ball Positions
     * @param m
     */
    void update(Memento* m){SavedState = m;}

    /**
     * @brief getCurrentState - Access the current BallPosition state
     * @return
     */
    Memento* getCurrentState() const {return SavedState;}
private:
   Memento* SavedState;
};

#endif // CARETAKER_H
