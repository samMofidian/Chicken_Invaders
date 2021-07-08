#include "Controller.h"

Controller::Controller(int season, QObject *parent) : QObject(parent)
{
    // init season
    this->season = season;

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

void Controller::addSpaceCraft()
{
    spaceCraft = new SpaceCraft{scene, holder};
}
