#ifndef HEART_H
#define HEART_H


#include <QGraphicsTextItem>

class Heart: public QGraphicsTextItem{
public:

    Heart(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();

private:

    bool gameOver();
    int health;
};

#endif // HEART_H
