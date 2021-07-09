/* written & directed by sAm mofidian */
#include "View.h"
#include "SpaceCraft.h"

View::View(int season, int level) : QGraphicsView()
{
    // init level & season
    this->level = level;
    this->season = season;

    // viewController
    viewController = new Controller(season);

    // scene
    setScene(viewController->scene);

    // background image
    setBackgroundBrush(QBrush(QImage(":/image/back.jpg")));

    // fix size
    setFixedSize(1200, 750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // background music
    viewPlayer = new QMediaPlayer();
    viewPlayer->setMedia(QUrl("qrc:/music/level.mp3"));
    viewPlayer->play();

    // init seconds
    sec = 0;

    // stat Timer
    vtimer = new QTimer();
    vtimer->start(500);

    // connect to schedule
    connect(vtimer , SIGNAL(timeout()) , this , SLOT(schedule()));

    viewController->addSpaceCraft();
}

View::~View()
{
    delete vtimer;
    delete viewPlayer;
    delete viewController;
}

void View::schedule()
{

    // level 1
//    if (season == 1 && level == 1)
//    {

//    }

//    // level 2
//    if (season == 1 && level == 2)
//    {

//    }

//    // level 3
//    if (season == 2 && level == 3)
//    {

//    }

//    // level 4
//    if (season == 2 && level == 4)
//    {

//    }

    // level 5
    if (season == 3 && level == 5)
    {
        if(sec != 0 && sec % 15000 == 0)
        {
            viewController->addGift();
        }
        sec += 750;
    }

    // level 6
    if (season == 3 && level == 6)
    {
        if(sec != 0 && sec % 15000 == 0)
        {
            viewController->addGift();
        }
        sec += 750;
    }

}

/* written & directed by sAm mofidian */
