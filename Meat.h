#ifndef MEAT_H
#define MEAT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Meat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class Bullet;

public:

        Meat( QGraphicsScene * meatScene, QTimer * meattimer, int limitX, int limitY, QGraphicsItem * parent = 0 );
        Meat();
        void setX( int x );
        void setY( int y );
        void addMeat( int x, int y );
        ~Meat();

private:

        QGraphicsScene * meatScene;
        QTimer * meattimer;
        int limitX;
        int limitY;
        int numberOfMeats;

signals:

    public slots:

        void meatmove();


};

#endif // MEAT_H
