
#ifndef GIFT_H
#define GIFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Gift : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QGraphicsScene * giftScene;
    int timeIntervals;

public:
    explicit Gift(QGraphicsScene *giftScene, QTimer * timer, QGraphicsItem * parent = nullptr);

signals:

public slots:

    void move();

};

#endif // GIFT_H
