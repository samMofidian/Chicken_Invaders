/* written & directed by sAm mofidian*/
#include "Bullet.h"
#include "Egg.h"
#include "Chicken.h"
#include "Hen.h"
#include "Superhen.h"
#include "Score.h"
#include "SpaceCraft.h"
#include <QGraphicsScene>

int Bullet::numberOfChickens = 0;

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

void Bullet::chickSound()
{
//    QMediaPlayer* chick = new QMediaPlayer();
//    chick->setMedia(QUrl("qrc:/music/chick.mp3"));

//    if(chick->state() == QMediaPlayer::PlayingState)
//    {
//        chick->setPosition(0);
//    }
//    else if(chick->state() == QMediaPlayer::StoppedState)
//    {
//        chick->play();
    //    }
}

void Bullet::setNum(int n)
{
     numberOfChickens = n;
}

void Bullet::addNum(int n)
{
     numberOfChickens += n;
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

            // chick sound
            //chickSound();

            // count
            //++numberOfChickens;

            // delete
            scene()->removeItem(this);
            delete this;
        }

        if(SpaceCra)
        if(typeid(*(collidingList)[i]) == typeid(Hen))
        {
            (dynamic_cast<Hen *>(collidingList[i]))->hendecrementLives();

            // chick sound
            //chickSound();

            // count
            //++numberOfChickens;

            // delete
            scene()->removeItem(this);
            delete this;
        }

        if(typeid(*(collidingList)[i]) == typeid(Superhen))
        {
            (dynamic_cast<Superhen *>(collidingList[i]))->superhendecrementLives();

            // chick sound
            //chickSound();

            // count
            //++numberOfChickens;

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
