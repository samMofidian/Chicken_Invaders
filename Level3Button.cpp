#include "Level3button.h"
#include "View.h"

Level3Button::Level3Button(QGraphicsScene * scene) : level3Scene{scene}
{
    // init click
    click = false;

    // image
    setPixmap(QPixmap(":/image/lvl3.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(500, 50);

    // music
    level3ButtonMusic = new QMediaPlayer();
    level3ButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));
}

void Level3Button::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    level3ButtonMusic->play();
    auto myView = new View(3);
    myView->show();
}

Level3Button::~Level3Button()
{
    delete level3Scene;
    delete level3ButtonMusic;
}
