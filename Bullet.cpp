#include "Bullet.h"
#include <QGraphicsScene>

Bullet::Bullet(const int & velocity, QGraphicsItem * parent) : QObject(),
    QGraphicsPixmapItem(parent), velocity{velocity}
{
    // image
    setPixmap(QPixmap(":/image/bullet.png"));
}

void Bullet::moveToUp()
{
    setPos(x(), y() + velocity);

    // bullet out of screen
    if(y() > 750){
        scene()->removeItem(this);
        delete this;
    }
}
