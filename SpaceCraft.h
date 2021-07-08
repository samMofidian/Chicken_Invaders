#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class SpaceCraft : public QObject , public QGraphicsPixmapItem
{


private:

    int lives;
    QGraphicsScene * craftScene;

public:

    SpaceCraft(QGraphicsScene * craftScene, QGraphicsItem *parent);
    void keyPressEvent(QKeyEvent * event);
    void decrementLive();

};

#endif // SPACECRAFT_H
