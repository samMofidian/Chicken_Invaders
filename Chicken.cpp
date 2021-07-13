#include "Chicken.h"
#include "SpaceCraft.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Chicken::Chicken( QGraphicsScene * chickScene, QGraphicsItem * parent, int lives, Score * cscore, QTimer * timer )
    : QObject(), QGraphicsPixmapItem( parent ), chickScene( chickScene ), lives{lives}, cscore(cscore)
{
    // set picture
    setPixmap(QPixmap(":/image/joojeh1.png"));
    //setPixmap(QPixmap(":/image/hen.png"));

    // set chicken sound
    chickPlayer = new QMediaPlayer();
    chickPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

    // add to scene
    int sec = 0;
    sec ++;
    chickScene->addItem( this );

    // connect timer to move
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );

    // timer
    timer = new QTimer( this );
    timer->start(50);

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

}

Chicken::~Chicken()
{
    delete chickPlayer;
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

            // delete
            scene()->removeItem(this);
            delete this;
            return;
         }
     }
     /* written & directed by sAm mofidian */

    setPos( x(), y() + 6 );

}

void Chicken::decrementLives()
{
    // decrement chickens lives
    -- lives;

    // remove and delete if lives == 0
    if( lives == 0 ){
        cscore->addScore(5);
        scene()->removeItem( this );
        delete this;
    }
}
