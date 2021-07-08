#include "View.h"

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

    // bachground music
    viewPlayer = new QMediaPlayer();
    viewPlayer->setMedia(QUrl("qrc:/music/level.mp3"));
    viewPlayer->play();

    //init seconds
    sec = 0;
}

View::~View()
{
    delete vtimer;
    delete viewPlayer;
    delete viewController;
}
