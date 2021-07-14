/* elham zahir */
#include "Chicken.h"
#include "SpaceCraft.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Chicken::Chicken( QGraphicsScene * chickScene, QGraphicsItem * parent, int lives, Score * cscore, QTimer * timer, int limitY )
    : QObject(), QGraphicsPixmapItem( parent ), chickScene( chickScene ), lives{lives}, cscore(cscore), limitY{limitY}
{
    // set picture
    setPixmap(QPixmap(":/image/joojeh1.png"));

    // add to scene
    int sec = 0;
    sec ++;
    chickScene->addItem( this );

    // connect timer to move
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );

    // timer
    timer = new QTimer( this );
    timer->start(50);

    // init layers
    layers = 0;

}

Chicken::Chicken() : QObject(), QGraphicsPixmapItem(), chickScene( chickScene ), lives{1}
{
    // set picture
    setPixmap(QPixmap(":/image/joojeh1.png"));

    chickScene->addItem( this );

    // timer
    timer = new QTimer( this );
    timer->start(50);

    // connect timer to move
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );

    // init limit
    this->limitY = limitY;

}

void Chicken::decrementCount()
{
    --count;
}

void Chicken::move()
{
    /* written & directed by sAm mofidian */
    QList <QGraphicsItem *> collidingList = collidingItems();

     // decrement live
     for(size_t i{0}; i < collidingList.size(); ++i)
     {
         if(typeid(*(collidingList)[i])==typeid (SpaceCraft))
          {
                (dynamic_cast<SpaceCraft *>(collidingList[i]))->decrementLive();

                // add score
                cscore->addScore(5);

                // crash sound
                QMediaPlayer* crash = new QMediaPlayer();
                crash->setMedia(QUrl("qrc:/music/crash.mp3"));

                if(crash->state() == QMediaPlayer::PlayingState)
                {
                    crash->setPosition(0);
                }
                else if(crash->state() == QMediaPlayer::StoppedState)
                {
                    crash->play();
                }

                // add num
                Bullet::addNum(1);

                // delete
                scene()->removeItem(this);
                delete this;
                return;
          }
    }
     /* written & directed by sAm mofidian */

     if( y() <= limitY )
     {
     setPos( x(), y() + 6 );
     }

     /* sAm mofidian */
     // layers
     if(layers % 2 == 0)
     {
         setPixmap(QPixmap(":/image/joojeh1.png"));
     }
     if(layers % 2 == 1)
     {
         setPixmap(QPixmap(":/image/joojeh2.png"));
     }
     layers += 1;
     /* sAm mofidian */
}

void Chicken::decrementLives()
{
    // decrement chickens lives
    -- lives;

    // remove and delete if lives == 0
    if( lives == 0 ){
        /* sAm mofidian */
        cscore->addScore(5);
        Bullet::addNum(1);
        /* sAm mofidian */
        scene()->removeItem( this );
        delete this;
    }
}

/* elham zahir */
