#ifndef MAKEBALLCOMMAND_H
#define MAKEBALLCOMMAND_H

#include <QObject>
#include <QVector2D>
#include "abstractcommand.h"
#include "poolgame.h"
class MakeBallCommand : public AbstractCommand
{  
public:

    MakeBallCommand(PoolGame* game, QVector2D pos);
    ~MakeBallCommand();
    void execute();

private:
    PoolGame * _responseGame;
    QVector2D  m_pos;
};

#endif // MAKEBALLCOMMAND_H
