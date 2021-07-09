/* written & directed by sAm mofidian */
#ifndef NEXT_H
#define NEXT_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsSceneMouseEvent>

class Next : public QGraphicsPixmapItem
{


private:

    int level;
    bool click;
    QGraphicsScene * nextScene;
    QMediaPlayer * nextMusic;

public:

    Next(QGraphicsScene * scene, int level);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Next();
};

#endif // NEXT_H

/* written & directed by sAm mofidian */
