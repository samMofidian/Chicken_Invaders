#ifndef CHICKEN1_H
#define CHICKEN1_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMovie>
#include <QLabel>
#include <QMediaPlayer>

#include <QObject>

class Chicken1 : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    int lives;
    int pixPer40MiliSec;
    int Layer;
    QMediaPlayer *chickenMusic;

public:

    explicit Chicken1(const int& pixPer40MiliSec, QTimer *timer, const int lives, QGraphicsItem *parent);
    ~Chicken1();
    void decrementLives();
    int getLives();
    void setLives(int lives);

signals:

};

#endif // CHICKEN1_H
