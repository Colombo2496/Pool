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

    /* Getter methods
     */
    /**
     * @brief getVelocity - returns an array of the velocities stored
     * @return
     */
    std::vector<QVector2D>*  getVelocity() {return &m_velocity;}

    std::vector<QVector2D>* getPosition(){return &m_position;}

private:
    std::vector<QVector2D> m_velocity;
    std::vector<QVector2D> m_position;
};

#endif // ORIGINATOR_H
