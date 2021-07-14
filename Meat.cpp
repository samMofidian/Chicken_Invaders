#include "Meat.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QFont>

Meat::Meat( QGraphicsScene * meatScene, QTimer * meattimer, int limitX, int limitY, QGraphicsItem * parent )
    : QObject(), QGraphicsPixmapItem(parent), meatScene( meatScene ), limitX{limitX}, limitY{limitY}
{
    // set picture
    setPixmap(QPixmap(":/image/meat.png"));

    // add to scene
    meatScene->addItem( this );

    // connect timer to move
    connect( meattimer, SIGNAL(timeout()), this, SLOT( meatmove()) );

    // timer
    meattimer = new QTimer( this );
    meattimer->start(50);

    setPos( limitX, limitY );
}

Meat::Meat()
: QObject(), QGraphicsPixmapItem(), meatScene( meatScene )
{
    // set picture
    setPixmap(QPixmap(":/image/meat.png"));

    // add to scene
    meatScene->addItem( this );

    // timer
    meattimer = new QTimer( this );
    meattimer->start(50);

    // connect timer to move
    connect( meattimer, SIGNAL(timeout()), this, SLOT(meatmove()) );

    setPos( limitX, limitY );

}

void Meat::addMeat( int x, int y )
{
    this->limitX = x;
    this->limitY = y;
}

void Meat::meatmove()
{
    setPos( x() , y() + 6);
    if( y() >= 700)
    {
        setPos( x(), 700 );
        meatScene->removeItem(this);
        delete this;
    }
}
