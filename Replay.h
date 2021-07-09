#ifndef REPLAY_H
#define REPLAY_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsSceneMouseEvent>

class Replay : public QGraphicsPixmapItem
{


private:

    int season;
    int level;
    bool click;
    QGraphicsScene * replayScene;
    QMediaPlayer * replayMusic;

public:

    Replay(QGraphicsScene * scene, int season, int level);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Replay();

};

#endif // REPLAY_H
