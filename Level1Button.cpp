#include "Level1Button.h"
#include "View.h"

Level1Button::Level1Button(QGraphicsScene * scene) : level1Scene{scene}
{
    // init click
    click = false;

    // image
    setPixmap(QPixmap(":/image/lvl1.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(300, 50);

    // music
    level1ButtonMusic = new QMediaPlayer();
    level1ButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));
}

void Level1Button::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    level1ButtonMusic->play();
    auto myView = new View(1);
    myView->show();
}

Level1Button::~Level1Button()
{
    delete level1Scene;
    delete level1ButtonMusic;
}
