/* written & directed by sAm mofidian */
#include "Next.h"
#include "View.h"

Next::Next(QGraphicsScene * scene, int level) : nextScene{scene}
{
    // init click
    click = false ;

    // image
    setPixmap(QPixmap(":/image/next.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(100, 100);

    // music
    nextMusic = new QMediaPlayer();
    nextMusic->setMedia(QUrl("qrc:/music/click.mp3"));

    // set level
    this->level = level;

}

void Next::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;

    nextMusic->play();

    if(level == 1)
    {
        auto myView = new View(1, level + 1);
        myView->show();
    }

    if(level == 2)
    {
        auto myView = new View(2, level + 1);
        myView->show();
    }
    if(level == 3)
    {
        auto myView = new View(2, level + 1);
        myView->show();
    }

    if(level == 4)
    {
        auto myView = new View(3, level + 1);
        myView->show();
    }

    if(level == 5)
    {
        auto myView = new View(3, level + 1);
        myView->show();
    }
}

Next::~Next()
{
    delete nextScene;
    delete nextMusic;
}

/* written & directed by sAm mofidian */
