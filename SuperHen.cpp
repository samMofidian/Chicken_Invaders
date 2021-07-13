/* elham zahir */
#include "Superhen.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

SuperHen::SuperHen( QGraphicsScene * superhenScene, QGraphicsItem * parent, int superhenlives, Score * sscore, QTimer * superhentimer )
    : QObject(), QGraphicsPixmapItem( parent ), superhenScene( superhenScene ), superhenlives{superhenlives}, sscore(sscore)
{
    // set picture
    setPixmap(QPixmap(":/image/s1.png"));
    //setPixmap(QPixmap(":/image/hen.png"));

    // set chicken sound
    superhenPlayer = new QMediaPlayer();
    superhenPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

    // add to scene
    //chicken * chick = new Chicken[5];
    //for( int i = 0 ; i < 5 ; i ++ ){
        int sec = 0;
        sec ++;
    superhenScene->addItem( this );
    //}
    //setPos( 1000, 0 );
    //setPos( 500, 0 );

    // connect timer to move
    connect( superhentimer, SIGNAL(timeout()), this, SLOT(superhenmove()) );

    // timer


    superhentimer = new QTimer( this );
    superhentimer->start(50);

}

SuperHen::SuperHen()
: QObject(), QGraphicsPixmapItem(), superhenScene( superhenScene ), superhenlives{2}
{
    // set picture
    setPixmap(QPixmap(":/image/s1.png"));
    //setPixmap(QPixmap(":/image/hen.png"));

    // set chicken sound
    //chickPlayer = new QMediaPlayer();
    //chickPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

    superhenScene->addItem( this );
    //}
    //setPos( 1000, 0 );
    //setPos( 500, 0 );

    // timer
    superhentimer = new QTimer( this );
    superhentimer->start(50);

    // connect timer to move
    connect( superhentimer, SIGNAL(timeout()), this, SLOT(move()) );

}

SuperHen::~SuperHen()
{
    delete superhenPlayer;
}

void SuperHen::superhenmove()
{
    //Chicken * chick = new Chicken{ chickScene, parent, lives, timer}[5];
    //for( int i = 0 ; i < 5 ; i ++ ){/*
//    int sec = 0;
//    sec ++;
    //setPos( 1000, 0 );
    //if( y() != 450 ){
    setPos( x(), y() + 6 );
    //}
    //}


    /* sAm mofidian */
    QList <QGraphicsItem *> collidingList = collidingItems();

     // decrement live
     for(size_t i{0}; i < collidingList.size(); ++i)
     {
         if(typeid(*(collidingList)[i])==typeid (SpaceCraft))
          {
            (dynamic_cast<SpaceCraft *>(collidingList[i]))->decrementLive();

            // add score
            sscore->addScore(15);

            // delete
            scene()->removeItem(this);
            delete this;
            return;
         }
     }
    /* sAm mofidian */
}

void SuperHen::superhendecrementLives()
{
    // decrement chickens lives
    -- superhenlives;

    // remove and delete if lives == 0
    if( superhenlives == 0 ){
        /* sAm mofidian */
        sscore->addScore(15);
        /* sAm mofidian */
        scene()->removeItem( this );
        delete this;
    }
}

/* elham zahir */
