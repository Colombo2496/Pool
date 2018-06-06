#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <QVector2D>


//If possible create a SINGLETON
class GameStats
{
public:
    GameStats(unsigned int cueSunk = 0): m_CueSunk(cueSunk){}


    /*Get methods
     */
    /**
     * @brief getAccuracy
     * @return the accuracy for it
     */
    QVector2D* getAccuracy(){return &m_accuracy;}
    unsigned int* getCueSinking(){ return &m_CueSunk;}

    /* Update Methods
     */
    /**
     * @brief updateAccuracy - Updates the accuracy
     * @param ballHit if TRUE update the hit Rate
     * ELSE update the total amount of times hit
     */
    void updateAccuracy(bool ballHit);
    /**
     * @brief updateCueSinking
     * @param value = 0 by default. Can either increase or decrease time
     * Decrease used for Memento
     */
    void updateCueSinking(){m_CueSunk++;}
private:
    QVector2D m_accuracy;
    unsigned int m_CueSunk;
};

#endif // GAMESTATS_H
