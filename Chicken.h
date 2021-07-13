/* elham zahir */
#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include "Score.h"
#include "SpaceCraft.h"

class Chicken : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:
        Chicken( QGraphicsScene * chickScene, QGraphicsItem * parent, int lives, Score * escore, QTimer * timer );
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

signals:

public slots:
        void move();
        void decrementLives();

};

#endif // CHICKEN_H

/* elham zahir */
