/* written & directed by sAm mofidian */
#include "Replay.h"
#include "View.h"

Replay::Replay(QGraphicsScene * scene, int season, int level) : replayScene{scene}
{
    // init click
    click = false;

    // image
    setPixmap(QPixmap(":/image/replay.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(625, 575);

    // music
    replayMusic = new QMediaPlayer();
    replayMusic->setMedia(QUrl("qrc:/music/click.mp3"));

    // set season and level
    this->season = season;
    this->level = level;
}

void Replay::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    click = true;
    replayMusic->play();
    auto myView = new View(season, level);
    myView->show();
}

Replay::~Replay()
{
    delete replayScene;
    delete replayMusic;
}

/* written & directed by sAm mofidian */
