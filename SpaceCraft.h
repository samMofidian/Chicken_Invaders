#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"

class SpaceCraft : public QObject , public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    int lives;
    QGraphicsScene * craftScene;
    bool click;

public:

    SpaceCraft(QGraphicsScene * craftScene, QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    void decrementLive();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    QTimer * stimer;
    Bullet * bullet;

signals:

public slots:


};

#endif // SPACECRAFT_H
