#include "originator.h"


void Originator::setState(std::vector<Ball *> state)
{

    for(Ball *b : state){
            Stage2Ball *newBall = new Stage2Ball;
        newBall->setColour(b->colour());
        newBall->setPosition(b->position());
        newBall->setRadius(b->radius());
        newBall->setStrength(INFINITY);
        newBall->setVelocity(b->velocity());
//        newBall.setColour(b->colour());
//        newBall.setMass(b->mass());
//        newBall.setPosition(b->position());
//        newBall.setRadius(b->radius());
//        newBall.setStrength(INFINITY);
//        newBall.setVelocity(b->velocity());
        m_state.push_back(newBall);
    }
//    m_state.push_back(&newBall);
//    m_state = state;
}

Memento* Originator::saveToMemento()
{
    Memento* miniSave = new Memento(this->m_state);
    return miniSave;
}

void Originator::restoreFromMemento(Memento *prevState)
{
    m_state = prevState->getState();
}


