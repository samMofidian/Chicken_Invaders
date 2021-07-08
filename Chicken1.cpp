#include "Chicken1.h"
#include <QGraphicsScene>
#include <QList>

Chicken1::Chicken1(const int& pixPer40MiliSec , QTimer *timer,
                   const int lives, QGraphicsItem *parent) : QObject(),
    QGraphicsPixmapItem (parent), pixPer40MiliSec{pixPer40MiliSec}, lives{lives}
{

    // music
    chickenMusic = new QMediaPlayer();
    chickenMusic->setMedia(QUrl("qrc:/music/.mp3"));
}

Chicken1::~Chicken1()
{
    delete chickenMusic;
}

void Chicken1::decrementLives()
{
    if (lives != 0 )
    {
    --lives;
    }

    if(lives==0)
    {
        scene()->removeItem(this);
    }
}

int Chicken1::getLives()
{
    return lives;
}
