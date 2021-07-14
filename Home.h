/* written & directed by sAm mofidian */
#ifndef HOME_H
#define HOME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsSceneMouseEvent>

class Home : public QGraphicsPixmapItem
{


private:

    bool click;
    QGraphicsScene * homeScene;
    QMediaPlayer * homeMusic;

public:

    Home(QGraphicsScene * scene, bool islvl6);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    ~Home();
};

#endif // HOME_H

/* written & directed by sAm mofidian */
