/* written & directed by sAm mofidian*/
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

    // start Timer
    menuTimer = new QTimer();
    menuTimer->start(1000);
    connect(menuTimer , SIGNAL(timeout()) , this , SLOT(menuSchedule()));

    // levels
    lvl1 = new Level1Button(menuScene);
    lvl2 = new Level2Button(menuScene);
    lvl3 = new Level3Button(menuScene);
    lvl4 = new Level4Button(menuScene);
    lvl5 = new Level5Button(menuScene);
    lvl6 = new Level6Button(menuScene);

    // exit
    exit = new ExitButton(menuScene);

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

    if(lvl1->click == true || lvl2->click == true || lvl3->click == true
            || lvl4->click == true || lvl5->click == true || lvl6->click == true || exit->click == true){
        menuMusic->stop();
        this->close();
    }
}

/* written & directed by sAm mofidian*/
