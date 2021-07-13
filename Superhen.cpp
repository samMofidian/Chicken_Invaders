#include "Superhen.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Superhen::Superhen( QGraphicsScene * superhenScene, QGraphicsItem * parent, int superhenlives, Score * sscore, QTimer * superhentimer )
    : QObject(), QGraphicsPixmapItem( parent ), superhenScene( superhenScene ), superhenlives{4}, sscore(sscore)
{
    // set picture
    setPixmap(QPixmap(":/image/s1.png"));

    // set chicken sound
    superhenPlayer = new QMediaPlayer();
    superhenPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

    // add to scene
    int sec = 0;
    sec ++;
    superhenScene->addItem( this );


    // connect timer to move
    connect( superhentimer, SIGNAL(timeout()), this, SLOT(superhenmove()) );

    // time
    superhentimer = new QTimer( this );
    superhentimer->start(50);

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

Superhen::~Superhen()
{
    delete superhenPlayer;
}

void Superhen::superhenmove()
{
    setPos( x(), y() + 6 );
}

void Superhen::superhendecrementLives()
{

    -- superhenlives;

    // remove and delete if lives == 0
    if( superhenlives == 0 ){
        sscore->addScore(15);
        scene()->removeItem( this );
        delete this;
    }
}
