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
        :m_position(pos),m_radius(r)
    {}
    void draw(QPainter &p);
    bool encompassed(QVector2D circleCentre, float r)
    {
        return (circleCentre-m_position).length() + r < m_radius;
    }

private:
    QVector2D m_position;
    float m_radius;
};

#endif // POCKET_H
