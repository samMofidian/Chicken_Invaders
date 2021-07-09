/* written & directed by sAm mofidian */
#include "Level2button.h"
#include "View.h"

Level2Button::Level2Button(QGraphicsScene * scene) : level2Scene{scene}
{
    // init click
    click = false;

    // image
    setPixmap(QPixmap(":/image/lvl2.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(400, 50);

    // music
    level2ButtonMusic = new QMediaPlayer();
    level2ButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));
}

void Level2Button::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    level2ButtonMusic->play();
    auto myView = new View(1, 2);
    myView->show();
}

Level2Button::~Level2Button()
{
    delete level2Scene;
    delete level2ButtonMusic;
}

/* written & directed by sAm mofidian */
