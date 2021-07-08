#include "SpaceCraft.h"

SpaceCraft::SpaceCraft(QGraphicsScene * craftScene) : craftScene{craftScene}
{

    setPixmap(QPixmap(":/image/lvl1.png"));
    craftScene->addItem(this);
    setPos(600, 650);
}

void SpaceCraft::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        setPos(x()-15, y());
    }
    if (event->key() == Qt::Key_Right)
    {
        setPos(x()+15, y());
    }
    if (event->key() == Qt::Key_Space)
    {
        exit(1);
    }
}
