/* written & directed by sAm mofidian*/
#include "Bullet.h"
#include "Egg.h"
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

    // break egg
    for(size_t i{0} ; i < collidingList.size(); ++i)
    {
        if(typeid(*(collidingList)[i]) == typeid(Egg))
        {
            (dynamic_cast<Egg *>(collidingList[i]))->breakEgg();

            // delete
            scene()->removeItem(this);
            delete this;
        }
    }

    /* elham zahir */

    QList <QGraphicsItem *> collList = collidingItems();

            // decrement chickens lives;
            for( size_t i = 0 ; i < collList.size() ; i ++ ){
                if( typeid( * ( collList[i] ) ) == typeid( Chicken ) ){
                    dynamic_cast<Chicken *>( collList[i] )->decrementLives();
                    scene()->removeItem(this);
                    delete this;
                    //score = 0;
                   // score->addScore(5);
                }
            }

            QList <QGraphicsItem *> collList2 = collidingItems();

                    // decrement chickens lives;
                    for( size_t i = 0 ; i < collList2.size() ; i ++ ){
                        if( typeid( * ( collList2[i] ) ) == typeid( Hen ) ){
                            dynamic_cast<Hen *>( collList2[i] )->hendecrementLives();
                            scene()->removeItem(this);
                            delete this;
                            //score = 0;
                           // score->addScore(5);
                        }
                    }

                    QList <QGraphicsItem *> collList3 = collidingItems();

                            // decrement chickens lives;
                            for( size_t i = 0 ; i < collList3.size() ; i ++ ){
                                if( typeid( * ( collList3[i] ) ) == typeid( SuperHen ) ){
                                    dynamic_cast<SuperHen *>( collList3[i] )->superhendecrementLives();
                                    scene()->removeItem(this);
                                    delete this;
                                    //score = 0;
                                   // score->addScore(5);
                                }
                            }

                            /* elham zahir */


    // pos
    setPos(x(), y() - 40);

    // delete bullet out of screen
    if (y() < 1)
    {
        scene()->removeItem(this);
        delete this;
    }

}

/* written & directed by sAm mofidian*/
