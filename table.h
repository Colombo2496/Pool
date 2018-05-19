#ifndef TABLE_H
#define TABLE_H

#include <QPainter>

#include "changeinpoolgame.h"

/**
 * @brief The Table class represents a basic pool table with a size and surface friction.
 * concrete subclasses should override the draw function to enable drawing the table
 */
class Table
{
public:
    Table(float width, float height,float friction)
        :m_width(width), m_height(height), m_friction(friction){}
    virtual ~Table(){}


    float width()const{return m_width;}
    float height()const{return m_height;}

    /**
     * @brief get the coefficient of friction for the table
     * this is the proportion of velocity lost each second by object moving on the table
     * @return the friction coefficient
     */
    float friction()const{return m_friction;}

    ChangeInPoolGame virtual ballCollision(Ball *ball) = 0;


    /**
     * @brief draws a table
     * @param painter used to draw the table
     */
    virtual void draw(QPainter & p) = 0;

protected:
    float m_width;
    float m_height;
    float m_friction;
};

#endif // TABLE_H
