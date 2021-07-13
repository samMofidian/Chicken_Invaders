/* elham zahir */
#include "Chicken.h"
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
    //chicken * chick = new Chicken[5];
    //for( int i = 0 ; i < 5 ; i ++ ){
        int sec = 0;
        sec ++;
    chickScene->addItem( this );
    //}
    //setPos( 1000, 0 );
    //setPos( 500, 0 );

    // connect timer to move
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );

    // timer


    timer = new QTimer( this );
    timer->start(50);

}

Chicken::Chicken()
: QObject(), QGraphicsPixmapItem(), chickScene( chickScene ), lives{1}
{
    // set picture
    setPixmap(QPixmap(":/image/joojeh1.png"));
    //setPixmap(QPixmap(":/image/hen.png"));

    // set chicken sound
    //chickPlayer = new QMediaPlayer();
    //chickPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

    chickScene->addItem( this );
    //}
    //setPos( 1000, 0 );
    //setPos( 500, 0 );

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
    //Chicken * chick = new Chicken{ chickScene, parent, lives, timer}[5];
    //for( int i = 0 ; i < 5 ; i ++ ){/*
//    int sec = 0;
//    sec ++;
    //setPos( 1000, 0 );
    //if( y() != 450 ){
    setPos( x(), y() + 6 );

    /* sAm mofidian */
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
    /* sAm mofidian */

    /* sAm mofidian */
    int layers = 0;

    if (layers % 2 == 0)
    {
        setPixmap(QPixmap(":/image/joojeh1.png"));
    }

    if (layers % 2 == 1)
    {
        setPixmap(QPixmap(":/image/joojeh2.png"));
    }
    /* sAm mofidian */
    //}
    //}
}

void Chicken::decrementLives()
{
    // decrement chickens lives
    -- lives;

    // remove and delete if lives == 0
    if( lives == 0 ){
        /* sAm mofidian */
        cscore->addScore(5);
        /* sAm mofidian */
        scene()->removeItem( this );
        delete this;
    }
}

/* elham zahir */
