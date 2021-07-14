#ifndef MEAT_H
#define MEAT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <MeatScore.h>

class Meat : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

    friend class Bullet;

    public:

        Meat( QGraphicsScene * meatScene, QTimer * meattimer, MeatScore * meatscore, int limitX, int limitY, QGraphicsItem * parent = 0 );
        Meat();
        void setX( int x );
        void setY( int y );
        void addMeat( int x, int y );
        void deleteMeat();

    private:

        QGraphicsScene * meatScene;
        QTimer * meattimer;
        int limitX;
        int limitY;
        int numberOfMeats;
        MeatScore * meatscore;

signals:

public slots:

        void meatmove();


};

#endif // MEAT_H
