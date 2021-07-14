/* elham zahir */
#include "MeatScore.h"
#include <QFont>

int MeatScore::meatscore = 0;

MeatScore::MeatScore(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    meatscore = 0;
    setPlainText(QString("MEAT: ") + QString::number(meatscore));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times", 18));
}

void MeatScore::addMeatScore(int score)
{
    meatscore += score;

    if( meatscore == 30 )
    {
        meatscore = 0;
    }

    setPlainText(QString("MEAT: ") + QString::number(meatscore));
}

int MeatScore::getMeatScore()
{
    return meatscore;
}

void MeatScore::setMeatScore(int score)
{
    meatscore = score;
    setPlainText(QString("MEAT: ") + QString::number(meatscore));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times", 18));
}

/* elham zahir */
