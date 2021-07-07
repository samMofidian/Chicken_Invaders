#include "Menu.h"

Menu::Menu() : QGraphicsView()
{
    // scene
    menuScene = new QGraphicsScene();
    menuScene->setSceneRect(0,0,1200,750);
    setScene(menuScene);

    // image
    setBackgroundBrush(QBrush(QImage(":/image/mainmenu.png")));


    // fix size
    setFixedSize(1200,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // music
    menuMusic = new QMediaPlayer();
    menuMusic->setMedia(QUrl("qrc:/music/test.mp3"));
    menuMusic->play();
}

Menu::~Menu()
{
    delete menuMusic;
    delete menuScene;
}
