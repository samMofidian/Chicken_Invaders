/* written & directed by sAm mofidian */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QTimer>
#include <SpaceCraft.h>
#include <Score.h>
#include <Gift.h>
#include <Egg.h>
#include <Life.h>
#include <Chicken.h>
#include <Hen.h>
#include <SuperHen.h>


class Controller : public QObject
{

    friend class View;

    Q_OBJECT

private:

    QGraphicsScene * scene;
    QGraphicsRectItem * holder;
    QTimer * ctimer;
    int season;
    SpaceCraft * spaceCraft;
    Score * score;
    QList<Gift *> giftList;
    QList<Egg *> eggList;
    Life * life;
    /* elham zahir */
    int lvl;
    QList<Chicken *> chickList;
    QList<Hen *>henList;
    QList<SuperHen *>superhenList;
    int chickLives;
    /* elham zahir */

public:

    explicit Controller(int season, int lvl, QObject *parent = nullptr);
    ~Controller();
    void addSpaceCraft();
    void addGift();
    void addEgg();
    bool game_over();
    void addLife();
    /* elham zahir */
    void addChick();
    /* elham zahir */

signals:

};

#endif // CONTROLLER_H

/* written & directed by sAm mofidian */
