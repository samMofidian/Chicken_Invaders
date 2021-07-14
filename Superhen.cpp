/* elham zahir */
#include "Superhen.h"
#include "SpaceCraft.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Superhen::Superhen( QGraphicsScene * superhenScene, QGraphicsItem * parent, int superhenlives, Score * sscore, QTimer * superhentimer, int limitY )
    : QObject(), QGraphicsPixmapItem( parent ), superhenScene( superhenScene ), superhenlives{4}, sscore(sscore), limitY{limitY}
{
    // set picture
    setPixmap(QPixmap(":/image/s1.png"));

    // add to scene
    superhenScene->addItem( this );

    // connect timer to move
    connect( superhentimer, SIGNAL(timeout()), this, SLOT(superhenmove()) );

    // time
    superhentimer = new QTimer( this );
    superhentimer->start(50);

    // init layers
    layers = 0;

}

Superhen::Superhen() : QObject(), QGraphicsPixmapItem(), superhenScene( superhenScene ), superhenlives{4}
{
    // set picture
    setPixmap(QPixmap(":/image/s1.png"));

    // add to scene
    superhenScene->addItem( this );

    // timer
    superhentimer = new QTimer( this );
    superhentimer->start(50);

    // connect timer to move
    connect( superhentimer, SIGNAL(timeout()), this, SLOT(move()) );

}

void Superhen::superhenmove()
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
            sscore->addScore(15);

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
     if(layers % 4 == 0)
     {
         setPixmap(QPixmap(":/image/s1.png"));
     }
     if(layers % 4 == 1)
     {
         setPixmap(QPixmap(":/image/s2.png"));
     }
     if(layers % 4 == 2)
     {
         setPixmap(QPixmap(":/image/s3.png"));
     }
     if(layers % 4 == 3)
     {
         setPixmap(QPixmap(":/image/s4.png"));
     }
     layers++;
     /* sAm mofidian */
}

/* sAm mofidian, elham zahir */
void Superhen::superhendecrementLives(int n)
{
    // decrement chickens lives
    superhenlives -= n;

    // remove and delete if lives == 0
    if( superhenlives < 1 )
    {
        sscore->addScore(15);
        Bullet::addNum(1);

        scene()->removeItem( this );
        delete this;
    }
}
/* sAm mofidian, elham zahir */

/* elham zahir */
