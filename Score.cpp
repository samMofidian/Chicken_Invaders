/* written & directed by sAm mofidian */
#include "Score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    playerScore = 0;
    setPlainText(QString::number(playerScore));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 18));
}


void Score::addToScore(int score)
{
    playerScore += score;
    setPlainText(QString::number(playerScore));
}

int Score::getScore()
{
    return playerScore;
}

void Score::setScore(int score)
{
    playerScore = score;
    setPlainText(QString::number(playerScore));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 18));
}

/* written & directed by sAm mofidian */
