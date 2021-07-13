/* elham zahir */
#ifndef HEN_H
#define HEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include "Score.h"
#include "SpaceCraft.h"

class Hen : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Hen( QGraphicsScene * henScene, QGraphicsItem * parent, int henlives, Score * hscore, QTimer * hentimer );
        Hen();
        ~Hen();

    private:
        QGraphicsScene * henScene;
        QMediaPlayer * henPlayer;
        int henlives;
        QTimer * hentimer;
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