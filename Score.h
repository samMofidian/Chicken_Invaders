/* written & directed by sAm mofidian */
#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsSimpleTextItem>

class Score : public QGraphicsTextItem
{

    friend class Egg;
    friend class Chicken;
    friend class Hen;
    friend class Superhen;
    friend class Bullet;

private:

    int playerScore;

public:

    Score(QGraphicsItem * parent = 0);
    void addScore(int s);
    int getScore();
    void setScore(int score);
};

#endif // SCORE_H

/* written & directed by sAm mofidian*/
