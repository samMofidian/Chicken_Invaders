#include "Hen.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Hen::Hen( QGraphicsScene * chickScene, QGraphicsItem * parent, int henlives, Score * hscore, QTimer * hentimer )
    : QObject(), QGraphicsPixmapItem( parent ), henScene( henScene ), henlives{2}, timeIntervals{0}, hscore(hscore)
{
    // set picture
    setPixmap(QPixmap(":/image/1.png"));

    // set chicken sound
    henPlayer = new QMediaPlayer();
    henPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

    // add to scene
    int sec = 0;
    sec ++;
    chickScene->addItem( this );

    // connect timer to move
    connect( hentimer, SIGNAL(timeout()), this, SLOT(henmove()) );

    // timer
    hentimer = new QTimer( this );
    hentimer->start(50);

}

Hen::Hen() : QObject(), QGraphicsPixmapItem(), henScene( henScene ), henlives{2}, timeIntervals{0}
{
    // set picture
    setPixmap(QPixmap(":/image/1.png"));

    // add to scene
    henScene->addItem( this );

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

    ++timeIntervals;
    setPos(x() , y() + 6);

    if( timeIntervals == 1 )
    {
        setPos( x(), y() - 6 );
    }
}

void Hen::hendecrementLives()
{
    // decrement chickens lives
    -- henlives;

    // change the picture if lives == 0
    if( henlives == 0 ){
        hscore->addScore(10);
        scene()->removeItem( this );
        delete this;
    }
}
