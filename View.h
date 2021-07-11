/* written & directed by sAm mofidian */
#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include "Controller.h"
#include "Replay.h"
#include "Home.h"
#include "Next.h"
#include "GameOverImage.h"
#include "WinImage.h"

class View : public QGraphicsView
{

    Q_OBJECT

private:

    QTimer * vtimer;
    int sec;
    Controller * viewController;
    QMediaPlayer * viewPlayer;
    QMediaPlayer * gameOverMusic;
    QMediaPlayer * winMusic;
    int level;
    int season;
    GameOverImage * gameOver;
    WinImage * win;
    Replay * replayButton;
    Next * nextButton;
    Home * homeButton;

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
