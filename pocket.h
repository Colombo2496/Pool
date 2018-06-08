#ifndef POCKET_H
#define POCKET_H

#include <QPainter>
#include <QVector2D>

/**
 * @brief The Pocket class simply represents a pocket on the table
 */
class Pocket
{
public:
    Pocket(QVector2D pos, float r)
        :m_position(pos),m_radius(r), counter(0)
    {}
    void draw(QPainter &p);
    bool encompassed(QVector2D circleCentre, float r)
    {
        return (circleCentre-m_position).length() + r < m_radius;
    }

    /**
     * @brief getCounter - the current amount of balls sunk.
     * @return counter
     */
    int getCounter() const{return this->counter;}

    /**
     * @brief updateCounter - Updated everytime a ball fell into the pocket
     */
    void updateCounter(int i = 1){this->counter = this->counter + i;}

private:
    QVector2D m_position;
    float m_radius;
    unsigned int counter;
};

#endif // POCKET_H
