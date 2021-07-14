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

    private:

        QGraphicsScene * henScene;
        int henlives;
        QTimer * hentimer;
        int limitY;
        /* sAm mofidian */
        Score * hscore;
        int layers;
        /* sAm mofidian */

signals:

public slots:

        void henmove();
        /* sAm mofidian, elham zahir */
        void hendecrementLives(int n);
        /* sAm mofidian, elham zahir */

};

#endif // HEN_H

/* elham zahir */
