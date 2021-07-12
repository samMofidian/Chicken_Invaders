/* written & directed by sAm mofidian */
#include "Life.h"
#include <QFont>

Life::Life(SpaceCraft * space_craft, QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setPlainText(QString::number(space_craft->getLives()));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 22));
}

/* written & directed by sAm mofidian */

