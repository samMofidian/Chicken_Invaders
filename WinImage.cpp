/* written & directed by sAm mofidian */
#include "WinImage.h"

WinImage::WinImage(QGraphicsScene * scene) :winScene{scene}
{
    // image
    setPixmap(QPixmap(":/image/win.png"));

    // add to scene
    scene->addItem(this);

    // pos
    setPos(400, 125);
}

/* written & directed by sAm mofidian */
