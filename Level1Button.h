#ifndef LEVEL1BUTTON_H
#define LEVEL1BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Level1Button : public QGraphicsPixmapItem
{

    friend class Menu;

private:

    QGraphicsScene * level1Scene;
    QMediaPlayer * level1ButtonMusic;
    bool click;

public:

    Level1Button(QGraphicsScene * scene);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Level1Button();
};
#endif // LEVEL1BUTTON_H
