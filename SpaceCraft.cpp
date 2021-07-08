#include "SpaceCraft.h"

SpaceCraft::SpaceCraft()
{
    lives = 3;
    setPixmap(QPixmap(":/image/.png"));
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

    }
}
