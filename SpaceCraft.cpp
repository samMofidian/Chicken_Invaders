#include "SpaceCraft.h"
#include "Bullet.h"
#include <QGraphicsScene>

SpaceCraft::SpaceCraft(QGraphicsScene * craftScene, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), craftScene{craftScene}
{

    setPixmap(QPixmap(":/image/SpaceCraft.png"));
    craftScene->addItem(this);
    setPos(550, 550);
}

void SpaceCraft::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
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
    if (event->key() == Qt::Key_Space)
    {
        auto bullet = new Bullet(25);
        bullet->setPos(x() + 40, y() + 50);
        scene()->addItem(bullet);
    }
}
