/* written & directed by sAm mofidian */
#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <Score.h>

class Bullet : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QTimer * btimer;
    Score * bscore;

public:

    explicit Bullet(QGraphicsItem * parent = nullptr);
    Bullet(int t);
    void chickSound();

signals:

public slots:

    void moveToUp();

};

#endif // BULLET_H

/* written & directed by sAm mofidian */
