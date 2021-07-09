/* written & directed by sAm mofidian */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <SpaceCraft.h>
#include <Score.h>
#include <Gift.h>


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

public:

    explicit Controller(int season, QObject *parent = nullptr);
    ~Controller();
    void addSpaceCraft();
    void addGift();
    bool game_over();

signals:

};

#endif // CONTROLLER_H

/* written & directed by sAm mofidian */
