#include "originator.h"


void Originator::setState(std::vector<Ball *> state)
{

    for(Ball *b : state){

          QVector2D velocity = QVector2D(b->velocity().x(),b->velocity().y());
          QVector2D position = QVector2D(b->position().x(),b->position().y());
          m_velocity.push_back(velocity);
          m_position.push_back(position);
    }
}

Memento* Originator::saveToMemento()
{
    Memento* miniSave = new Memento(this->m_velocity,this->m_position);
    return miniSave;
}

void Originator::restoreFromMemento(Memento *prevState)
{

    Memento* m_state = prevState->getState();

    m_velocity = m_state->m_velocity;
    m_position = m_state->m_position;
}


