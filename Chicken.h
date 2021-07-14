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
    friend class Bullet;

    Q_OBJECT

    public:

        Chicken( QGraphicsScene * chickScene, QGraphicsItem * parent, int lives,Score * cscore, QTimer * timer,  int limitY );
        Chicken();
        void decrementCount();


    private:

        QGraphicsScene * chickScene;
        int lives;
        int limitY;
        int timeIntervals;
        int count;
        QTimer * timer;
        /* sAm mofidian */
        Score * cscore;
        int layers;
        /* sAm mofidian */

signals:

public slots:

        void move();
        void decrementLives();
};

#endif // CHICKEN_H

/* elham zahir */
