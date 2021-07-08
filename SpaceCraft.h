#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class SpaceCraft : public QGraphicsPixmapItem
{

private:

    int lives;

public:

    SpaceCraft();
    void keyPressEvent(QKeyEvent * event);
    void decrementLive();

};

#endif // SPACECRAFT_H
