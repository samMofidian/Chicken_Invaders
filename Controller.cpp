/* written & directed by sAm mofidian */
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

    // score
    score = new Score();
    scene->addItem(score);
    score->setPos(1140, 700);

    // timer
    ctimer = new QTimer();
    ctimer->start(40);

}

void Controller::addSpaceCraft()
{
    spaceCraft = new SpaceCraft{scene, holder};
    // focus
    spaceCraft->setFlag(QGraphicsItem::ItemIsFocusable);
    spaceCraft->setFocus();
}

void Controller::addGift()
{
    giftList.push_back(new Gift{scene, ctimer, holder});
}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}
