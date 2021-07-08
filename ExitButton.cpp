#include "ExitButton.h"
#include "View.h"

ExitButton::ExitButton(QGraphicsScene * scene) : exitButtonScene{scene}
{
    // init click
    click = false;

    // image
    setPixmap(QPixmap(":/image/exit.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(500, 650);

    // music
    exitButtonMusic = new QMediaPlayer();
    exitButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));

}

ExitButton::~ExitButton()
{
    delete exitButtonScene;
    delete exitButtonMusic;
}

void ExitButton::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    exitButtonMusic->play();
    exit(1);
}

