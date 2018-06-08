#ifndef CARETAKER_H
#define CARETAKER_H
#include "memento.h"
#include <vector>

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
    void update(Memento* m){SavedState.push_back(m);}

    /**
     * @brief getCurrentState - Access the current BallPosition state
     * @return
     */
    Memento* getCurrentState()  {
        Memento* memento = SavedState.at(SavedState.size()-1);
        //Prevents the original memento from being popped
        if(SavedState.size() >= 2)
            SavedState.pop_back();
        return memento;
                                }
private:
   std::vector<Memento*> SavedState;
};

#endif // CARETAKER_H
