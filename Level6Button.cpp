/* written & directed by sAm mofidian */
#include "Level6Button.h"
#include "View.h"

Level6Button::Level6Button(QGraphicsScene * scene) : level6Scene{scene}
{
    // init click
    click = false;

    // image
    setPixmap(QPixmap(":/image/lvl6.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(800, 50);

    // music
    level6ButtonMusic = new QMediaPlayer();
    level6ButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));
}

void Level6Button::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    level6ButtonMusic->play();
    auto myView = new View(3, 6);
    myView->show();
}

Level6Button::~Level6Button()
{
    delete level6Scene;
    delete level6ButtonMusic;
}

/* written & directed by sAm mofidian*/
