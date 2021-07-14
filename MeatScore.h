/* elham zahir */
#ifndef MEATSCORE_H
#define MEATSCORE_H


#include <QGraphicsSimpleTextItem>

class MeatScore : public QGraphicsTextItem
{

private:

    int meatscore;

public:

    MeatScore(QGraphicsItem * parent = 0);
    void addMeatScore(int s);
    int getMeatScore();
    void setMeatScore(int score);
};

#endif // MEATSCORE_H

/* elham zahir */
