#include "heart.h"
#include <QFont>

Heart::Heart(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Initialize to 3
    health = 3;

    // draw text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Heart::decrease(){
    health--;

        // Update the text
        setPlainText(QString("Health: ") + QString::number(health));

}

int Heart::getHealth(){
    return health;
}

bool Heart::gameOver(){
    return health < 1;
}
