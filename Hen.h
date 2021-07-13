/* elham zahir */
#ifndef HEN_H
#define HEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include "Score.h"

class Hen : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Hen( QGraphicsScene * henScene, QGraphicsItem * parent, int henlives, Score * hscore, QTimer * hentimer, int limitY );
        Hen();
        ~Hen();

    private:
        QGraphicsScene * henScene;
        QMediaPlayer * henPlayer;
        int henlives;
        QTimer * hentimer;
        int limitY;
        int timeIntervals;
        /* sAm mofidian */
        Score * hscore;
        /* sAm mofidian */

    public slots:
        void henmove();
        void hendecrementLives();

    signals:
};

#endif // HEN_H

/* elham zahir */
