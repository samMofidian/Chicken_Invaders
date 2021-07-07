#ifndef LEVEL3BUTTON_H
#define LEVEL3BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Level3Button : public QGraphicsPixmapItem
{

    friend class Menu;

private:

    QGraphicsScene * level3Scene;
    QMediaPlayer * level3ButtonMusic;
    bool click;

public:

    Level3Button(QGraphicsScene * scene);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Level3Button();
};
#endif // LEVEL3BUTTON_H
