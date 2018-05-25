#ifndef ORIGINATOR_H
#define ORIGINATOR_H
#include "memento.h"

/**
 * @brief The Originator class
 */
class Originator
{
public:

    Originator(){}
    ~Originator(){}
    /**
     * @brief setState set the current Snapshot of the originater
     * @param state
     */
    void setState(std::vector<Ball *> state);

    /**
     * @brief saveToMemento - Create a memento using the 'm_state'
     * @return
     */
    Memento* saveToMemento();

    /**
     * @brief restoreFromMemento - Restore the state that was saved by in the memento
     * @param prevState
     */
    void restoreFromMemento(Memento* prevState);

private:
    std::vector<Ball *> m_state;
};

#endif // ORIGINATOR_H
