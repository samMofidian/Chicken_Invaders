/* written & directed by sAm mofidian */
#ifndef GAMEOVERIMAGE_H
#define GAMEOVERIMAGE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsSceneMouseEvent>

class GameOverImage : public QGraphicsPixmapItem
{


private:

    QGraphicsScene * gameOverScene;

public:

   GameOverImage(QGraphicsScene * scene);

};

#endif // GAMEOVERIMAGE_H

/* written & directed by sAm mofidian */
