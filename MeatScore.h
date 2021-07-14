/* elham zahir */
#ifndef MEATSCORE_H
#define MEATSCORE_H


#include <QGraphicsSimpleTextItem>
#include <Score.h>

class MeatScore : public QGraphicsTextItem
{

private:

    static int meatscore;
    Score * mscore;

public:

    MeatScore(Score * mscore, QGraphicsItem * parent = 0);
    void addMeatScore(int s);
    int getMeatScore();
    void setMeatScore(int score);
};

#endif // MEATSCORE_H

/* elham zahir */
