#ifndef LEVEL4BUTTON_H
#define LEVEL4BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Level4Button : public QGraphicsPixmapItem
{

    friend class Menu;

private:

    QGraphicsScene * level4Scene;
    QMediaPlayer * level4ButtonMusic;
    bool click;

public:

    Level4Button(QGraphicsScene * scene);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Level4Button();
};

#endif // LEVEL4BUTTON_H
