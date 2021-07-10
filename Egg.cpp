/* written & directed by sAm mofidian */
#include "Egg.h"

Egg::Egg(QGraphicsScene * eggScene, QTimer * etimer, QGraphicsItem * parent) : QObject(),
    QGraphicsPixmapItem(parent), eggScene(eggScene), timeIntervals{0}
{
    // image
    setPixmap(QPixmap(":/image/egg.png"));

    // add to scene
    eggScene->addItem(this);
    setPos((rand() % 800) + 200, 0);

    // connect timer to fall
    connect(etimer, SIGNAL(timeout()), this, SLOT(fall()));
}

void Egg::fall()
{
    ++timeIntervals;
    setPos(x() , y() + 25);

    if(timeIntervals == 35 || y() > 745)
    {
        eggScene->removeItem(this);
        delete this;
    }
}
/* written & directed by sAm mofidian */
