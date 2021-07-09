/* written & directed by sAm mofidian */
#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class ExitButton : public QGraphicsPixmapItem
{

    friend class Menu;

private:

    QGraphicsScene * exitButtonScene;
    QMediaPlayer * exitButtonMusic;
    bool click;

public:

    ExitButton(QGraphicsScene * scene);
   ~ExitButton();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // EXITBUTTON_H

/* written & directed by sAm mofidian*/
