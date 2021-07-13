/* elham zahir */
#ifndef SUPERHEN_H
#define SUPERHEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>

class SuperHen : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        SuperHen( QGraphicsScene * henScene, QGraphicsItem * parent, int henlives, QTimer * hentimer );
        SuperHen();
        ~SuperHen();

    private:
        QGraphicsScene * superhenScene;
        QMediaPlayer * superhenPlayer;
        int superhenlives;
        QTimer * superhentimer;

    public slots:
        void superhenmove();
        void superhendecrementLives();

    signals:
};

#endif // SUPERHEN_H

/* elham zahir */
