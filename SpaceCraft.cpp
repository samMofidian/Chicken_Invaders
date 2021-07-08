#include "SpaceCraft.h"

SpaceCraft::SpaceCraft(QGraphicsScene * craftScene, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), craftScene{craftScene}
{

    setPixmap(QPixmap(":/image/lvl1.png"));
    craftScene->addItem(this);
    setPos(550, 550);
}

void SpaceCraft::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left)
    {
        setPos(x() - 15, y());
    }
    if (event->key() == Qt::Key_Right)
    {
        setPos(x() + 15, y());
    }
    if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y() + 10);
    }
    if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y() - 10);
    }
}
