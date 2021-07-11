/* written & directed by sAm mofidian */
#include "GameOverImage.h"

GameOverImage::GameOverImage(QGraphicsScene * scene) : gameOverScene{scene}
{
    // image
    setPixmap(QPixmap(":/image/game_over.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(400, 75);
}

/* written & directed by sAm mofidian */
