/* written & directed by sAm mofidian */
#ifndef WINIMAGE_H
#define WINIMAGE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsSceneMouseEvent>

class WinImage : public QGraphicsPixmapItem
{


private:

    QGraphicsScene * winScene;

public:

   WinImage(QGraphicsScene * scene);
};

#endif // WINIMAGE_H

/* written & directed by sAm mofidian */
