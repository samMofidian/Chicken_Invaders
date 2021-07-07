#include "View.h"

View::View() : QGraphicsView()
{
    // viewController
    viewController = new Controller();

    // scene
    setScene(viewController->scene);

    // background image
    setBackgroundBrush(QBrush(QImage(":/image/mainmenu.png")));

    // fix size
    setFixedSize(1200, 750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // bachground music
    viewPlayer = new QMediaPlayer();
    viewPlayer->setMedia(QUrl("qrc:/music/test.mp3"));
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
