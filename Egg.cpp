/* written & directed by sAm mofidian */
#include "Egg.h"
#include "SpaceCraft.h"
#include "Score.h"

Egg::Egg(QGraphicsScene * eggScene, QTimer * etimer, QGraphicsItem * parent) : QObject(),
    QGraphicsPixmapItem(parent), eggScene(eggScene), timeIntervals{0}
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
}

void Egg::fall()
{
    QList <QGraphicsItem *> collidingList = collidingItems();

     // decrement live
     for(size_t i{0}; i < collidingList.size(); ++i)
     {
         if(typeid(*(collidingList)[i])==typeid (SpaceCraft))
          {
            ( dynamic_cast<SpaceCraft *>(collidingList[i]))->decrementLive();

            // delete
            scene()->removeItem(this);
            delete this;
            return;
         }
     }

    ++timeIntervals;
    setPos(x() , y() + 25);

    if(timeIntervals == 35 || y() > 745)
    {
        eggScene->removeItem(this);
        delete this;
    }
}
/* written & directed by sAm mofidian */
