#include "Controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{

    // scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1200, 750);

    // holder
    holder = new QGraphicsRectItem();
    holder->setRect(0, 0, 1200, 750);
}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}
