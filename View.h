#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include "Controller.h"

class View : public QGraphicsView
{

    Q_OBJECT

private:

    QTimer * vtimer;
    int sec;
    Controller * viewController;
    QMediaPlayer * viewPlayer;
    int level;


public:

    explicit View(int level);
    ~View();

signals:

};

#endif // VIEW_H
