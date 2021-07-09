/* written & directed by sAm mofidian*/
#ifndef LEVEL6BUTTON_H
#define LEVEL6BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Level6Button : public QGraphicsPixmapItem
{

    friend class Menu;

private:

    QGraphicsScene * level6Scene;
    QMediaPlayer * level6ButtonMusic;
    bool click;

public:

    Level6Button(QGraphicsScene * scene);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Level6Button();
};

#endif // LEVEL6BUTTON_H

/* written & directed by sAm mofidian*/
