#ifndef STAGE3FACTORY_H
#define STAGE3FACTORY_H

#include <vector>
#include "stage2factory.h"
#include "statistics.h"

using namespace std;
class Dialog;
class PoolGame;

class Stage3Factory : public Stage2Factory
{
public:
    Stage3Factory(Dialog * Parent);
    virtual ~Stage3Factory();


protected:
    Statistics * m_statistics;
private:
    void setUpExtentions(Dialog *Parent);
    void setUpStatistics(vector<unsigned int *>* pocketStats = nullptr,PoolGame* game = nullptr);
};

#endif // STAGE3FACTORY_H
