#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class SpaceCraft : public QObject , public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    int lives;
    QGraphicsScene * craftScene;

public:

    SpaceCraft(QGraphicsScene * craftScene, QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    void decrementLive();

signals:

public slots:

};

#endif // SPACECRAFT_H
