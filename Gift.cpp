/* written & directed by sAm mofidian */
#include "Gift.h"
#include "SpaceCraft.h"

Gift::Gift(QGraphicsScene *giftScene, QTimer * timer, QGraphicsItem * parent) : QObject(),
    QGraphicsPixmapItem(parent), giftScene(giftScene), timeIntervals{0}
{
    // image
    setPixmap(QPixmap(":/image/gift.png"));

    // add to scene
    giftScene->addItem(this);
    setPos(rand() % 1100, 0);

    // connect timer to move
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Gift::move()
{
    QList <QGraphicsItem *> collidingList = collidingItems();

     // change bullet type
     for(size_t i{0} ; i < collidingList.size(); ++i)
     {
         if(typeid(*(collidingList)[i])==typeid (SpaceCraft))
         {
            ( dynamic_cast<SpaceCraft *>(collidingList[i]))->changeShotType();

            // delete
            scene()->removeItem(this);
            delete this;
            return;
         }
     }

    ++timeIntervals;
    setPos(x() , y() + 30);

    if(timeIntervals == 25 || y() > 745)
    {
        giftScene->removeItem(this);
        delete this;
    }
}


/* written & directed by sAm mofidian */
