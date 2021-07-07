#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>

class Menu : public QGraphicsView
{

    Q_OBJECT

private:

    QGraphicsScene * menuScene;
    QMediaPlayer * menuMusic;

public:

    explicit Menu();
    ~Menu();

signals:

};

#endif // MENU_H
