#ifndef SAVELOADCOMMAND_H
#define SAVELOADCOMMAND_H
#include <QJsonValue>

class SaveLoadCommand
{
public:
    virtual void execute() = 0;
};


/**
 * @brief The gameSaveCommand class - Activates when player wants to save current game
 */
class gameSaveCommand : public SaveLoadCommand
{
public:
    void execute(){/*TODO*/};
};

/**
 * @brief The gameLoadCommand class
 */
class gameLoadCommand : public SaveLoadCommand
{
public:
    void exectute(){/*TODO*/};
};

#endif // SAVELOADCOMMAND_H
