/* written & directed by sAm mofidian */
#include "Egg.h"
#include "SpaceCraft.h"
#include "Score.h"

Egg::Egg(QGraphicsScene * eggScene, QTimer * etimer, Score * escore, QGraphicsItem * parent) : QObject(),
    QGraphicsPixmapItem(parent), eggScene(eggScene), escore(escore), timeIntervals{0}
{
    // image
    setPixmap(QPixmap(":/image/egg.png"));

    // add to scene
    eggScene->addItem(this);
    setPos((rand() % 800) + 200, 175);

    // connect timer to fall
    connect(etimer, SIGNAL(timeout()), this, SLOT(fall()));
}

void Egg::breakEgg()
{
    scene()->removeItem(this);
    escore->addScore(5);
}

void Egg::fall()
{
    QList <QGraphicsItem *> collidingList = collidingItems();

     // decrement live
     for(size_t i{0}; i < collidingList.size(); ++i)
     {
         if(typeid(*(collidingList)[i])==typeid (SpaceCraft))
          {
            (dynamic_cast<SpaceCraft *>(collidingList[i]))->decrementLive();

            // add score
            escore->addScore(5);

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

    ++timeIntervals;
    setPos(x() , y() + 25);

    if(y() > 724)
    {
        setPixmap(QPixmap(":/image/egg-2.png"));
        /* elham zahir */
        setPos( x(), y() - 25 );
        /* elham zahir */
    }


    if(timeIntervals == 35 || y() > 750)
    {
        eggScene->removeItem(this);
        delete this;
    }
}
/* written & directed by sAm mofidian */
