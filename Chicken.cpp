#include "Chicken.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Chicken::Chicken( QGraphicsScene * chickScene, QGraphicsItem * parent, int lives, QTimer * timer )
    : QObject(), QGraphicsPixmapItem( parent ), chickScene( chickScene ), lives{lives}
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

    //chscore = new Score();
}

Chicken::~Chicken()
{
    delete chickPlayer;
}

void Chicken::move()
{

    setPos( x(), y() + 6 );

}

void Chicken::decrementLives()
{
    // decrement chickens lives
    -- lives;

    // remove and delete if lives == 0
    if( lives == 0 ){
        scene()->removeItem( this );
        delete this;
    }
}
