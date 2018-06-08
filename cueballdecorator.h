#ifndef CUEBALLDECORATOR_H
#define CUEBALLDECORATOR_H
#include "balldecorator.h"

#include "dialog.h"

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QSize>
#include <QMediaPlayer>
#include <QKeyEvent>
#include "caretaker.h"
#include "originator.h"

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

    /**
     * @brief showPopup - Window pops up instructing user what to do. It'll dissapear in 3s
     * @param insideBaulk - If true displays message instructing to place CUE
     * inside behind (on the left hand side) of the baulk line.
     * Otherwise instruct the player to palce the cue inside the baulk zone.
     */
    void showPopup(bool wrongPlacement);
public slots:
    void mousePressed(QMouseEvent * event);
    void mouseMoved(QMouseEvent * event);
    void mouseReleased(QMouseEvent * event);
    void placeCueBall(QSize tableDimensions);
    void keyPressed(QKeyEvent *event);
    void keyReleased(QKeyEvent *event);


private:
    void setUpPopUp();
    QVector2D endpoint;
    QVector2D mousePos;
    bool clicked;
    bool placeCue;
    QSize baulkZone;
    QLabel popup;
    QMediaPlayer hitCueSound;

    bool m_keyPressed;
    Caretaker savedData;
};

#endif // CUEBALLDECORATOR_H
