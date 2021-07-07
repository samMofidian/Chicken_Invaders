#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include "Level1Button.h"
#include "Level2Button.h"
#include "Level3Button.h"
#include "Level4Button.h"
#include "Level5Button.h"
#include "Level6Button.h"
#include "ExitButton.h"

class Menu : public QGraphicsView
{

    Q_OBJECT

private:

    QGraphicsScene * menuScene;
    QMediaPlayer * menuMusic;
    QTimer *menuTimer;
    Level1Button * lvl1;
    Level2Button * lvl2;
    Level3Button * lvl3;
    Level4Button * lvl4;
    Level5Button * lvl5;
    Level6Button * lvl6;
    ExitButton * exit;


public:

    explicit Menu();
    ~Menu();

signals:

public slots:

    void menuSchedule();

};

#endif // MENU_H
