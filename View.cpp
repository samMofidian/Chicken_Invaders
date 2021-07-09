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

    // game over music
    gameOverMusic = new QMediaPlayer();
    gameOverMusic->setMedia(QUrl("qrc:/music/.mp3"));

    // stat Timer
    vtimer = new QTimer();
    vtimer->start(500);

    // connect to schedule
    connect(vtimer , SIGNAL(timeout()) , this , SLOT(schedule()));

    viewController->addSpaceCraft();
}

void View::pause()
{
    vtimer->stop();
    viewController->ctimer->stop();
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

    // loose game
    if(viewController->game_over()==true)
    {
        pause();
        viewPlayer->stop();
        gameOverMusic->play();
        QGraphicsPixmapItem * gameOver = new QGraphicsPixmapItem();
        gameOver->setPixmap(QPixmap(":/image/"));
        viewController->scene->addItem(gameOver);
        gameOver->setPos(0,0);
        replayButton = new Replay(viewController->scene, season, level);

    }
}

/* written & directed by sAm mofidian */
