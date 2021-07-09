/* written & directed by sAm mofidian*/
#include "Bullet.h"
#include <QGraphicsScene>

Bullet::Bullet(QGraphicsItem * parent) : QObject(),
    QGraphicsPixmapItem(parent)
{
    // image
    setPixmap(QPixmap(":/image/bullet.png"));

    // make timer
    btimer = new QTimer(this);

    // connect to moveToUp
    connect(btimer , SIGNAL(timeout()) ,this , SLOT(moveToUp()));

    // start timer
    btimer->start(45);
}

void Bullet::moveToUp()
{

    setPos(x(), y() - 40);

    // delete bullet out of screen
    if (y() < 1)
    {
        scene()->removeItem(this);
        delete this;
    }

}

/* written & directed by sAm mofidian*/
