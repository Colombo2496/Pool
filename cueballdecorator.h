#ifndef CUEBALLDECORATOR_H
#define CUEBALLDECORATOR_H
#include "balldecorator.h"

#include "dialog.h"

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QSize>

/**
 * @brief The CueBallDecorator class is the decorator that turns a ball into a cue ball
 */
class CueBallDecorator : public BallDecorator, public QObject
{
public:
    /**
     * @brief CueBallDecorator decorates a ball to be used as a cue ball
     * @param b is the ball to be decorated
     * @param parent is the parent Dialog, this is used to connect to the signals it emits
     */
    CueBallDecorator(Ball * b, Dialog * parent);
    void draw(QPainter &p);
public slots:
    void mousePressed(QMouseEvent * event);
    void mouseMoved(QMouseEvent * event);
    void mouseReleased(QMouseEvent * event);
    void placeCueBall(QSize tableDimensions);

private:
    QVector2D endpoint;
    QVector2D mousePos;
    bool clicked;
    bool placeCue;
    QSize baulkZone;
};

#endif // CUEBALLDECORATOR_H
