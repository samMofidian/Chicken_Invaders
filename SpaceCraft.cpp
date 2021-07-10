/* written & directed by sAm mofidian*/
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

    // init shot type
    shotType = 1;

    // init lives
    lives = 3;
}

void SpaceCraft::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        setPos(x() - 25, y());
        //qInfo() << "move left";
    }
    else if (event->key() == Qt::Key_Right)
    {
        setPos(x() + 25, y());
        //qInfo() << "move right";
    }
    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y() - 20);
        //qInfo() << "move up";
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y() + 20);
        //qInfo() << "move down";
    }
    else if (event->key() == Qt::Key_Space)
    {
        if (shotType == 1)
        {
            bullet = new Bullet();
            bullet->setPos(x() + 40, y() - 40);
            scene()->addItem(bullet);
            //qInfo() << "shot";
        }
        if (shotType == 2)
        {
            bullet = new Bullet(1);
            bullet->setPos(x() + 30, y() - 40);
            scene()->addItem(bullet);
        }
    }
}

void SpaceCraft::decrementLive()
{
    --lives;
}

void SpaceCraft::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    bullet = new Bullet();
    bullet->setPos(x() + 40, y() - 40);
    scene()->addItem(bullet);
}

void SpaceCraft::changeShotType()
{
    shotType = 2;
}

int SpaceCraft::getLives()
{
    return lives;
}

/* written & directed by sAm mofidian*/

