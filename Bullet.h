/* written & directed by sAm mofidian */
#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bullet : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QTimer * btimer;

public:

    explicit Bullet(QGraphicsItem * parent = nullptr);
    void setBullet(int t);

signals:

public slots:

    void moveToUp();

};

#endif // BULLET_H

/* written & directed by sAm mofidian */
