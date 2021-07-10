/* written & directed by sAm mofidian */
#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Egg : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QGraphicsScene * eggScene;
    int timeIntervals;

public:

    explicit Egg(QGraphicsScene * eggScene, QTimer * etimer, QGraphicsItem * parent = nullptr);

signals:

public slots:

    void fall();

};

#endif // EGG_H

/* written & directed by sAm mofidian */
