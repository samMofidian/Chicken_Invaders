/* elham zahir */
#include "Hen.h"
#include "SpaceCraft.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Hen::Hen( QGraphicsScene * chickScene, QGraphicsItem * parent, int henlives, Score * hscore, QTimer * hentimer, int limitY )
    : QObject(), QGraphicsPixmapItem( parent ), henScene( henScene ), henlives{2}, timeIntervals{0}, hscore(hscore), limitY{limitY}
{
    // set picture
    setPixmap(QPixmap(":/image/1.png"));

    // set chicken sound
    henPlayer = new QMediaPlayer();
    henPlayer->setMedia(QUrl("qrc:/music/test.mp3"));

    // add to scene
    chickScene->addItem( this );

    // connect timer to move
    connect( hentimer, SIGNAL(timeout()), this, SLOT(henmove()) );

    // timer
    hentimer = new QTimer( this );
    hentimer->start(50);

    // init layers
    layers = 0;

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

    /* written & directed by sAm mofidian */
    QList <QGraphicsItem *> collidingList = collidingItems();

     // decrement live
     for(size_t i{0}; i < collidingList.size(); ++i)
     {
         if(typeid(*(collidingList)[i])==typeid (SpaceCraft))
          {
            (dynamic_cast<SpaceCraft *>(collidingList[i]))->decrementLive();

            // add score
            hscore->addScore(10);

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

            // delete
            scene()->removeItem(this);
            delete this;
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
         setPixmap(QPixmap(":/image/h1.png"));
     }
     if(layers % 4 == 1)
     {
         setPixmap(QPixmap(":/image/h2.png"));
     }
     if(layers % 4 == 2)
     {
         setPixmap(QPixmap(":/image/h3.png"));
     }
     if(layers % 4 == 3)
     {
         setPixmap(QPixmap(":/image/h4.png"));
     }
     layers++;
     /* sAm mofidian */
}

void Hen::hendecrementLives()
{
    // decrement chickens lives
    -- henlives;

    // change the picture if lives == 0
    if( henlives == 0 ){
        /* sAm mofidian */
        hscore->addScore(10);
        /* sAm mofidian */
        scene()->removeItem( this );
        delete this;
    }
}

/* elham zahir */
