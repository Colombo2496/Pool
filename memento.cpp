#include "memento.h"
Memento::Memento(std::vector<Ball *> newState):
    state(newState)
{
}

std::vector<Ball *> Memento::getState()
{
   return state;
}
