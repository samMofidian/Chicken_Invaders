#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <SpaceCraft.h>
#include <Score.h>


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


public:

    explicit Controller(int season, QObject *parent = nullptr);
    ~Controller();
    void addSpaceCraft();

signals:

};

#endif // CONTROLLER_H
