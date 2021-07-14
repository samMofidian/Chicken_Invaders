/* written & directed by sAm mofidian */
#include "Home.h"
#include "View.h"
#include "Menu.h"

Home::Home(QGraphicsScene * scene, bool islvl6) : homeScene{scene}
{
    // init click
    click = false ;

    // image
    setPixmap(QPixmap(":/image/home.png"));

    // add to scene
    scene->addItem(this);

    // pos
    if(islvl6 == false)
    {
       setPos(500, 575);
    }
    if(islvl6 == true)
    {
        setPos(562.5, 575);
    }


    // music
    homeMusic = new QMediaPlayer();
    homeMusic->setMedia(QUrl("qrc:/music/click.mp3"));
}

void Home::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    homeMusic->play();

    auto myHome = new Menu();
    myHome->show();
}

Home::~Home()
{
    delete homeScene;
    delete homeMusic;
}

/* written & directed by sAm mofidian */
