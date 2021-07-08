#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsSimpleTextItem>

class Score : public QGraphicsTextItem
{

    friend class Sun;

private:

    int playerScore;

public:

    Score(QGraphicsItem *parent = 0);
    void addToScore(int s);
    int getScore();
    void setScore(int score);
};

#endif // SCORE_H
