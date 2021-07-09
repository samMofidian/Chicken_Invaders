/* written & directed by sAm mofidian */
#include "Gift.h"

Gift::Gift(QGraphicsScene *giftScene, QTimer * timer, QGraphicsItem *parent) : QObject(),
    QGraphicsPixmapItem (parent), giftScene(giftScene), timeIntervals{0}
{
    // image
    setPixmap(QPixmap(":/image/gift.png"));

    // add to scene
    giftScene->addItem(this);
    setPos(rand() % 1100, 0);

    // connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));
}

void Gift::move()
{
   ++timeIntervals;
    setPos(x() , y() + 35);

    if(timeIntervals == 20 || y() > 735)
    {
        giftScene->removeItem(this);
        delete this;
    }
}


/* written & directed by sAm mofidian */
