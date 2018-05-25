#include "originator.h"


void Originator::setState(std::vector<Ball *> state)
{
    m_state = state;
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


