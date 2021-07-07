#include "Level5Button.h"
#include "View.h"

Level5Button::Level5Button(QGraphicsScene * scene) : level5Scene{scene}
{
    // init click
    click = false;

    // image
    setPixmap(QPixmap(":/image/lvl5.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(700, 50);

    // music
    level5ButtonMusic = new QMediaPlayer();
    level5ButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));
}

void Level5Button::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    level5ButtonMusic->play();
    auto myView = new View(5);
    myView->show();
}

Level5Button::~Level5Button()
{
    delete level5Scene;
    delete level5ButtonMusic;
}
