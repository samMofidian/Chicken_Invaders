/* written & directed by sAm mofidian */
#ifndef LEVEL5BUTTON_H
#define LEVEL5BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Level5Button : public QGraphicsPixmapItem
{

    friend class Menu;

private:

    QGraphicsScene * level5Scene;
    QMediaPlayer * level5ButtonMusic;
    bool click;

public:

    Level5Button(QGraphicsScene * scene);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Level5Button();
};

#endif // LEVEL5BUTTON_H

/* written & directed by sAm mofidian*/
