#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include "poolgame.h"
//#include "statistics.h"

/**
 * @brief The Dialog class starts up and displays a poolgame
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Dialog constructor
     * @param game is a pointer to a PoolGame, this takes ownership of that pointer
     * @param parent is the parent widget
     */
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    /**
     * @brief starts the simulation
     */
    void start(PoolGame * game);

    /**
     * @brief draws the simulation
     */
    void paintEvent(QPaintEvent *);

    /**
     * @brief mousePressEvent just emits the mousePressed signal
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);

    /**
     * @brief mousePressEvent just emits the mouseMoved signal
     * @param event
     */
    void mouseMoveEvent(QMouseEvent *event);

    /**
     * @brief mousePressEvent just emits a mouseReleased signal
     * @param event
     */
    void mouseReleaseEvent(QMouseEvent *event);

    /**
     * @brief keyPressed just emits a keyPressed signal
     * @param event
     */
    void keyPressedEvent(QKeyEvent *event);

    /**
     * @brief keyReleaseEvent just emits a keyRelease signal
     * @param event
     */
    void keyReleaseEvent(QKeyEvent *event);
signals:
    void mousePressed(QMouseEvent * event);
    void mouseMoved(QMouseEvent * event);
    void mouseReleased(QMouseEvent * event);
    void placeCueBall(QSize tableDimensions);
    void keyPressed(QKeyEvent * event);
    void keyReleased(QKeyEvent * event);

public slots:
    void runSimulationStep();
private:
    PoolGame * m_game;
    QTimer * m_framerateTimer;
    QTimer * m_timestepTimer;
//    Statistics * stat;
};

#endif // DIALOG_H
