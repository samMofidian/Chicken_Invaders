/* elham zahir */
#include "Hen.h"
#include "SpaceCraft.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Hen::Hen( QGraphicsScene * chickScene, QGraphicsItem * parent, int henlives, Score * hscore, QTimer * hentimer, int limitY )
    : QObject(), QGraphicsPixmapItem( parent ), henScene( henScene ), henlives{2}, hscore(hscore), limitY{limitY}
{
    // set picture
    setPixmap(QPixmap(":/image/h1.png"));

    // add to scene
    chickScene->addItem( this );

    // connect timer to move
    connect( hentimer, SIGNAL(timeout()), this, SLOT(henmove()) );

    // timer
    hentimer = new QTimer( this );
    hentimer->start(50);

    // init layers
    layers = 0;

    // init bool
    existboolean = true;

}

Hen::Hen() : QObject(), QGraphicsPixmapItem(), henScene( henScene ), henlives{2}
{
    // set picture
    setPixmap(QPixmap(":/image/h1.png"));

    // add to scene
    henScene->addItem( this );

    // timer
    hentimer = new QTimer( this );
    hentimer->start(50);

    // connect timer to move
    connect( hentimer, SIGNAL(timeout()), this, SLOT(move()) );

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

/* sAm mofidian, elham zahir */
void Hen::hendecrementLives(int n)
{
    // decrement chickens lives
    henlives -= n;

    // change the picture if lives == 0
    if( henlives < 1 )
    {
        hscore->addScore(10);
        Bullet::addNum(1);
        existboolean = false;
        scene()->removeItem( this );
        delete this;
    }
}
/* sAm mofidian, elham zahir */

bool Hen::exist()
{
    return existboolean;
}

/* elham zahir */
