#ifndef LEVEL2BUTTON_H
#define LEVEL2BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Level2Button : public QGraphicsPixmapItem
{

    friend class Menu;

private:

    QGraphicsScene * level2Scene;
    QMediaPlayer * level2ButtonMusic;
    bool click;

public:

    Level2Button(QGraphicsScene * scene);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Level2Button();
};

#endif // LEVEL2BUTTON_H
