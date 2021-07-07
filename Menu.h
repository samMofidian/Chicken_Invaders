#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include "Level1Button.h"

class Menu : public QGraphicsView
{

    Q_OBJECT

private:

    QGraphicsScene * menuScene;
    QMediaPlayer * menuMusic;
    QTimer *menuTimer;
    Level1Button * lvl1;


public:

    explicit Menu();
    ~Menu();

signals:

public slots:

    void menuSchedule();

};

#endif // MENU_H
