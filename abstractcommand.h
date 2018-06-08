#ifndef AbstractCommand_H
#define AbstractCommand_H
#include <QJsonValue>

/**
 * @brief The AbstractCommand class
 *
 */
class AbstractCommand
{
public:
    virtual ~AbstractCommand(){}
    virtual void execute() = 0;
protected:
     AbstractCommand(){}
};

#endif // AbstractCommand_H
