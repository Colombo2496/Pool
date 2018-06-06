#ifndef STATISTICS_H
#define STATISTICS_H

#include <QWidget>
#include <QLabel>
#include <vector>

#include "poolgame.h"
#include "dialog.h"

using namespace std;
class statistics
{
public:
    statistics(Dialog &parent,vector<unsigned int*> pocketStats);

//    /* Update Methods
//     */
//    /**
//     * @brief updatePocketStats - Updates the pockets statistics
//     * @param index - which pocket will be updated
//     * @param newValue - the new value(if not specified nothing occurs)
//     */
//    void updatePocketStats(int const index,int newValue = 0);

    /* Getter Methods
     */
    /**
     * @brief getPocketStats
     * @return all the pocket statistics
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

private:
    vector<unsigned int*> m_pocketStats;
    vector<unsigned int*> m_accuracy;
    QLabel _popUp;
};

#endif // STATISTICS_H
