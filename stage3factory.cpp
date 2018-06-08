#include "stage3factory.h"

Stage3Factory::Stage3Factory(Dialog *Parent):Stage2Factory(Parent),
    m_statistics(nullptr)
{
    setUpExtentions(Parent);
}

Stage3Factory::~Stage3Factory()
{
    delete m_statistics;
}



void Stage3Factory::setUpExtentions(Dialog * Parent)
{
        m_statistics = new Statistics(Parent);
}

void Stage3Factory::setUpStatistics(vector<unsigned int *> *pocketStats, PoolGame *game)
{
    if(pocketStats != nullptr){
        m_statistics->setUpPocketPointers(pocketStats);
    }
    if(game != nullptr){
        m_statistics->setUpPointers(game);
    }
}
