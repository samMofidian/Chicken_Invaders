/* written & directed by sAm mofidian */
#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "Score.h"
#include "GameOverImage.h"

class Egg : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QGraphicsScene * eggScene;
    Score * escore;
    int timeIntervals;
    GameOverImage * g;

public:

    explicit Egg(QGraphicsScene * eggScene, QTimer * etimer, Score * escore, QGraphicsItem * parent = nullptr);
    void breakEgg();

signals:

public slots:

    void fall();

};

#endif // EGG_H

/* written & directed by sAm mofidian */
