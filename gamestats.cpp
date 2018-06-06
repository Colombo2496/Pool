#include "gamestats.h"
void GameStats::updateAccuracy(bool ballHit)
{
    if(ballHit)
    {
        m_accuracy.setX(m_accuracy.x() + 1);
    }else
    {
        m_accuracy.setY(m_accuracy.y() + 1);
    }
}
