#include "makeballcommand.h"

MakeBallCommand::MakeBallCommand(PoolGame * game,QVector2D pos)
{
    _responseGame = game;
    m_pos = pos;
}

MakeBallCommand::~MakeBallCommand(){};
void MakeBallCommand::execute()
{
    _responseGame->makeBall(m_pos);
}
