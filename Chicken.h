/* elham zahir */
#ifndef CHICKEN_H
#define CHICKEN_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include "Score.h"

class Chicken : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Chicken( QGraphicsScene * chickScene, QGraphicsItem * parent, int lives, Score * cscore, QTimer * timer );
        Chicken();
        ~Chicken();

    private:
        QGraphicsScene * chickScene;
        QMediaPlayer * chickPlayer;
        int lives;
        QTimer * timer;
        /* sAm mofidian */
        Score * cscore;
        /* sAm mofidian */

    public slots:
        void move();
        void decrementLives();

    signals:
};

#endif // CHICKEN_H

/* elham zahir */
