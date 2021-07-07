#include "Menu.h"

Menu::Menu() : QGraphicsView()
{
    // scene
    menuScene = new QGraphicsScene();
    menuScene->setSceneRect(0, 0, 1200, 750);
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

    //start Timer
    menuTimer = new QTimer();
    menuTimer->start(1000);
    connect(menuTimer , SIGNAL(timeout()) , this , SLOT(menuSchedule()));

    // level 1
    lvl1 = new Level1Button(menuScene);
}

Menu::~Menu()
{
    delete menuMusic;
    delete menuScene;
}

void Menu::menuSchedule()
{
    if(menuMusic->state() == QMediaPlayer::StoppedState )
        menuMusic->play();

    if(lvl1->click == true){
        menuMusic->stop();
        this->close();
    }
}
