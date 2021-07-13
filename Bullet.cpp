/* written & directed by sAm mofidian*/
#include "Bullet.h"
#include "Egg.h"
#include "Chicken.h"
#include "Hen.h"
#include "Superhen.h"
#include "Score.h"
#include <QGraphicsScene>

Bullet::Bullet(QGraphicsItem * parent) : QObject(),
    QGraphicsPixmapItem(parent)
{
    // image
    setPixmap(QPixmap(":/image/bullet.png"));

    // make timer
    btimer = new QTimer(this);

    // connect to moveToUp
    connect(btimer , SIGNAL(timeout()) ,this , SLOT(moveToUp()));

    // start timer
    btimer->start(45);
}

Bullet::Bullet(int t)
{
    // image
    setPixmap(QPixmap(":/image/bullet2.png"));

    // make timer
    btimer = new QTimer(this);

    // connect to moveToUp
    connect(btimer , SIGNAL(timeout()) ,this , SLOT(moveToUp()));

    // start timer
    btimer->start(45);
}

void Bullet::moveToUp()
{
    QList < QGraphicsItem * > collidingList = collidingItems();

    // kill
    for(size_t i{0} ; i < collidingList.size(); ++i)
    {
        if(typeid(*(collidingList)[i]) == typeid(Egg))
        {
            (dynamic_cast<Egg *>(collidingList[i]))->breakEgg();

            // delete
            scene()->removeItem(this);
            delete this;
        }

        if(typeid(*(collidingList)[i]) == typeid(Chicken))
        {
            (dynamic_cast<Chicken *>(collidingList[i]))->decrementLives();

            // delete
            scene()->removeItem(this);
            delete this;
        }

        if(typeid(*(collidingList)[i]) == typeid(Hen))
        {
            (dynamic_cast<Hen *>(collidingList[i]))->hendecrementLives();

            // delete
            scene()->removeItem(this);
            delete this;
        }

        if(typeid(*(collidingList)[i]) == typeid(Superhen))
        {
            (dynamic_cast<Superhen *>(collidingList[i]))->superhendecrementLives();

            // delete
            scene()->removeItem(this);
            delete this;
        }
    }


    // pos
    setPos(x(), y() - 40);

    // delete bullet out of screen
    if (y() < 1)
    {
        scene()->removeItem(this);
        delete this;
    }

}

/* written & directed by sAm mofidian */
