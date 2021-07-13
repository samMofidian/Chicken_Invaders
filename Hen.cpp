/* elham zahir */
#include "Hen.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Hen::Hen( QGraphicsScene * chickScene, QGraphicsItem * parent, int henlives, QTimer * hentimer )
    : QObject(), QGraphicsPixmapItem( parent ), henScene( henScene ), henlives{henlives}
{
    // set picture
    setPixmap(QPixmap(":/image/1.png"));
    //setPixmap(QPixmap(":/image/hen.png"));

    // set chicken sound
    henPlayer = new QMediaPlayer();
    henPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

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
    connect( hentimer, SIGNAL(timeout()), this, SLOT(henmove()) );

    // timer


    hentimer = new QTimer( this );
    hentimer->start(50);

}

Hen::Hen()
: QObject(), QGraphicsPixmapItem(), henScene( henScene ), henlives{2}
{
    // set picture
    setPixmap(QPixmap(":/image/1.png"));
    //setPixmap(QPixmap(":/image/hen.png"));

    // set chicken sound
    //chickPlayer = new QMediaPlayer();
    //chickPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

    henScene->addItem( this );
    //}
    //setPos( 1000, 0 );
    //setPos( 500, 0 );

    // timer
    hentimer = new QTimer( this );
    hentimer->start(50);

    // connect timer to move
    connect( hentimer, SIGNAL(timeout()), this, SLOT(move()) );

}

Hen::~Hen()
{
    delete henPlayer;
}

void Hen::henmove()
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
}

void Hen::hendecrementLives()
{
    // decrement chickens lives
    -- henlives;

    // remove and delete if lives == 0
    if( henlives == 0 ){
        scene()->removeItem( this );
        delete this;
    }
}

/* elham zahir */
