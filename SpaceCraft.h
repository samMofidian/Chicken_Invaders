/* written & directed by sAm mofidian */
#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"

class SpaceCraft : public QObject , public QGraphicsPixmapItem
{

    friend class Controller;

    Q_OBJECT

private:

    int lives;
    QGraphicsScene * craftScene;
    bool click;
    int shotType;
    QTimer * stimer;
    Bullet * bullet;

public:

    SpaceCraft(QGraphicsScene * craftScene, QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    void decrementLive();
    void setBullet();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void changeShotType();
    int getLives();

signals:

public slots:


};

#endif // SPACECRAFT_H

/* written & directed by sAm mofidian*/
