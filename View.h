/* written & directed by sAm mofidian */
#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include "Controller.h"
#include "Replay.h"

class View : public QGraphicsView
{

    Q_OBJECT

private:

    QTimer * vtimer;
    int sec;
    Controller * viewController;
    QMediaPlayer * viewPlayer;
    QMediaPlayer *gameOverMusic;
    int level;
    int season;
    Replay * replayButton;

public:

    explicit View(int season, int level);
    void pause();
    ~View();

signals:

public slots:

    void schedule();

};

#endif // VIEW_H

/* written & directed by sAm mofidian */
