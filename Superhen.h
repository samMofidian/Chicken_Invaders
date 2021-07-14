#ifndef SUPERHEN_H
#define SUPERHEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include "Score.h"

class Superhen : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

        Superhen( QGraphicsScene * henScene, QGraphicsItem * parent, int henlives, Score * sscore, QTimer * hentimer, int limitY );
        Superhen();

private:

        QGraphicsScene * superhenScene;
        int superhenlives;
        int limitY;
        QTimer * superhentimer;
        /* sAm mofidian */
        Score * sscore;
        int layers;
        /* sAm mofidian */

signals:


public slots:

        void superhenmove();
        void superhendecrementLives();

};

#endif // SUPERHEN_H
