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
        Superhen( QGraphicsScene * henScene, QGraphicsItem * parent, int henlives, Score * sscore, QTimer * hentimer );
        Superhen();
        ~Superhen();

    private:
        QGraphicsScene * superhenScene;
        QMediaPlayer * superhenPlayer;
        int superhenlives;
        QTimer * superhentimer;
        /* sAm mofidian */
        Score * sscore;
        /* sAm mofidian */

    public slots:
        void superhenmove();
        void superhendecrementLives();

    signals:
};

#endif // SUPERHEN_H
