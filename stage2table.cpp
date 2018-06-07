#include "stage2table.h"
#include "ball.h"

void Stage2Table::draw(QPainter &p)
{
    p.setPen(Qt::black);
    p.setBrush(QBrush(m_colour));
    p.drawRect(0,0,m_width,m_height);
    p.setBrush(QBrush(Qt::black));
    //drawing the balkline
//    p.drawLine(m_width - (m_height/2),0,m_width - (m_height/2),m_height); //bulkzone right
    p.drawLine((m_height/2),0,(m_height/2),m_height);    //bulkzone left

    for(Pocket * pocket: m_pockets)
    {
        pocket->draw(p);
    }
}

std::vector<unsigned int*> Stage2Table::getPocketStats()
{
    std::vector<unsigned int*> stats;
    for(Pocket *p : this->m_pockets){
        unsigned int counter = p->getCounter();
        stats.push_back(&counter);
    }
    return stats;
}

void Stage2Table::playCollision()
{
    if(collisionSound->state() == QMediaPlayer::PlayingState){
        collisionSound->setPosition(0);
    }else if(collisionSound->state() == QMediaPlayer::StoppedState){
        collisionSound->play();
    }
}

ChangeInPoolGame Stage2Table::ballCollision(Ball *b)
{
    for(Pocket * p: m_pockets)
    {
        if(p->encompassed(b->position(),b->radius()))
        {
            p->updateCounter();//when a ball goes in
            //Make sure the white ball does reset!
            return ChangeInPoolGame({b});
        }
    }

    //are we outside the bounds horizontally and getting further away?
    //if so reverse x velocity
    if((b->position().x()<b->radius() && b->velocity().x()<0) || (b->position().x()>width()-b->radius() && b->velocity().x()>0))
    {
        playCollision();
        return b->changeVelocity(QVector2D(-b->velocity().x()*2,0));
    }


    //same but vertical
    if((b->position().y()<b->radius() && b->velocity().y()<0) || (b->position().y()>height()-b->radius() && b->velocity().y()>0))
    {
        playCollision();
        return b->changeVelocity(QVector2D(0,-b->velocity().y()*2));
    }


    return ChangeInPoolGame();
}
