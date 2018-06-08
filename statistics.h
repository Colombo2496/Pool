#ifndef STATISTICS_H
#define STATISTICS_H

<<<<<<< HEAD
#include <QWidget>

class statistics
{
public:
    statistics();
};

#endif // STATISTICS_H
=======
//#include <QWidget>
#include <QLabel>
#include <vector>

#include "poolgame.h"
#include "dialog.h"
#include "gamestats.h"

using namespace std;
class Statistics : public QObject
{
public:

    Statistics(Dialog *parent);


    /* Getter Methods
     */
    /**
     * @brief getPocketStats
     * @return all the pocket Statistics
     */
    vector<unsigned int*>* const  getPocketStats() {return m_pocketStats;}

    /**
     * @brief getAccuracy - Calculates the accuracy based on
     * the values found in 'm_accuracy'<CUEBALLHIT, CUEBALLMISS>
     * @return accuracy with 2 decimal values
     */
    float const getAccuracy();

    /**
     * @brief statsToString - Makes all the stats into a string to be parsed through
     * @return
     */
   QString statsToString();

    /**
     * @brief setUpPointers - set up the pointers for the Stat variables
     */
    void setUpPointers(PoolGame* game);

    /**
     * @brief setUpPocketPointers - set up the pointers for the pocket stats
     * @param pocketStats
     */
    void setUpPocketPointers(vector<unsigned int*>* pocketStats);

public slots:
    void keyPressed(QKeyEvent * event);
    void keyReleased(QKeyEvent * event);

private:

    /**
     * @brief setUpPopUp - Adds: Palette,FrameStyle,Alignment,FixedSize
     */
    void setUpPopUp();



    vector<unsigned int*>* m_pocketStats;
    GameStats * ballStats;
    QLabel m_popUp;
};

#endif // STATISTICS_H
>>>>>>> statistics
