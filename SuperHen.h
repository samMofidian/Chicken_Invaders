/* elham zahir */
#ifndef SUPERHEN_H
#define SUPERHEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include "Score.h"
#include "SpaceCraft.h"

class SuperHen : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        SuperHen( QGraphicsScene * henScene, QGraphicsItem * parent, int henlives, Score * sscore, QTimer * hentimer );
        SuperHen();
        ~SuperHen();

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

/* elham zahir */
