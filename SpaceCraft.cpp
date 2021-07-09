#include "SpaceCraft.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <QDebug>

SpaceCraft::SpaceCraft(QGraphicsScene * craftScene, QGraphicsItem *parent) : QObject(),
    QGraphicsPixmapItem(parent), craftScene{craftScene}
{

    // image
    setPixmap(QPixmap(":/image/SpaceCraft.png"));
    craftScene->addItem(this);
    setPos(550, 560);

}

void SpaceCraft::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        setPos(x() - 15, y());
        //qInfo() << "move left";
    }
    else if (event->key() == Qt::Key_Right)
    {
        setPos(x() + 15, y());
        //qInfo() << "move right";
    }
    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y() - 10);
        //qInfo() << "move up";
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y() + 10);
        //qInfo() << "move down";
    }
    else if (event->key() == Qt::Key_Space)
    {
        bullet = new Bullet();
        bullet->setPos(x() + 40, y() - 40);
        scene()->addItem(bullet);
        //qInfo() << "shot";
    }
}

void SpaceCraft::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    bullet = new Bullet();
    bullet->setPos(x() + 40, y() - 40);
    scene()->addItem(bullet);
}

