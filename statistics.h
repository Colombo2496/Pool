#ifndef STATISTICS_H
#define STATISTICS_H

#include <QWidget>
#include <QLabel>
#include <vector>

#include "poolgame.h"
#include "dialog.h"

using namespace std;
class Statistics : public QObject
{
public:
    Statistics(Dialog *parent,PoolGame game);

    /* Getter Methods
     */
    /**
     * @brief getPocketStats
     * @return all the pocket Statistics
     */
    vector<unsigned int*> const getPocketStats() {return m_pocketStats;}

    /**
     * @brief getAccuracy - Calculates the accuracy based on
     * the values found in 'm_accuracy'<CUEBALLHIT, CUEBALLMISS>
     * @return accuracy with 2 decimal values
     */
    float getAccuracy();

    /**
     * @brief showStatistics - Will make the popUp window pop-Up
     */
    void showStatistics();

    /**
     * @brief statsToString - Makes all the stats into a string to be parsed through
     * @return
     */
    string statsToString();

public slots:
    void keyPressed(QKeyEvent * event);
    void keyReleased(QKeyEvent * event);

private:

    /**
     * @brief setUpPopUp - Adds: Palette,FrameStyle,Alignment,FixedSize
     */
    void setUpPopUp();
    /**
     * @brief setUpPointers - set up the pointers for the Stat variables
     */
    void setUpPointers(PoolGame game);


    vector<unsigned int*> m_pocketStats;
    QVector2D* m_accuracy;
    QLabel m_popUp;
};

#endif // STATISTICS_H
