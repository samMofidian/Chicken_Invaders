#ifndef HEN_H
#define HEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>

class Hen : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Hen( QGraphicsScene * henScene, QGraphicsItem * parent, int henlives, QTimer * hentimer );
        Hen();
        ~Hen();

    private:
        QGraphicsScene * henScene;
        QMediaPlayer * henPlayer;
        int henlives;
        QTimer * hentimer;
        int timeIntervals;

    public slots:
        void henmove();
        void hendecrementLives();

    signals:
};

#endif // HEN_H
