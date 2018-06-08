#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMediaPlayer>
#include "poolgame.h"
#include "makeballcommand.h"

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
     * @brief mouseDoubleClickEvent tells a command to create a new ball in PoolGame
     * @param event
     */
    void mouseDoubleClickEvent(QMouseEvent * event);

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
     * @brief keyPressEvent - emits signal when Keyboard key is pressed
     * @param event
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief keyReleaseEvent - emits signal when Keyboard key is released
     * @param event
     */
    void keyReleaseEvent(QKeyEvent *event);

    /**
     * @brief restoreMove - Will activate the memento in m_game
     */
    void restoreMove();

signals:
    void mousePressed(QMouseEvent * event);
    void mouseMoved(QMouseEvent * event);
    void mouseReleased(QMouseEvent * event);
    void placeCueBall(QSize tableDimensions);
    void keyPressed(QKeyEvent * event);
    void keyReleased(QKeyEvent * event);

public slots:
    void runSimulationStep();
    /**
     * @brief playMusic - Play the background music or pause it
     * @param stop if TRUE pause it else play it
     */
    void playMusic(bool stop);
private:
    PoolGame * m_game;
    QTimer * m_framerateTimer;
    QTimer * m_timestepTimer;
    QMediaPlayer * ambientNoise;
    bool stopMusic;
    bool m_keyPressed;
};

#endif // DIALOG_H
