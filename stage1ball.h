#ifndef STAGEONEBALL_H
#define STAGEONEBALL_H

#include <QColor>
#include <QPainter>

#include "ball.h"

/**
 * @brief The Stage1Ball class is a concrete version of the Ball class specific to stage one of the assignment
 */
class Stage1Ball : public Ball
{
public:
    Stage1Ball();

    // Ball interface
public:
    /**
     * @brief draw the ball
     * @param painter to use to draw the ball
     */
    void draw(QPainter &p);
};

#endif // STAGEONEBALL_H
