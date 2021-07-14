/* elham zahir */
#include "Meat.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QFont>
#include "SpaceCraft.h"
#include "MeatScore.h"

Meat::Meat( QGraphicsScene * meatScene, QTimer * meattimer, MeatScore * meatscore, int limitX, int limitY, QGraphicsItem * parent )
    : QObject(), QGraphicsPixmapItem(parent), meatScene( meatScene ), limitX{limitX}, limitY{limitY}, meatscore(meatscore)
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

    // pos
    setPos( limitX, limitY );
}

Meat::Meat() : QObject(), QGraphicsPixmapItem(), meatScene( meatScene )
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

    // pos
    setPos( limitX, limitY );

}

void Meat::addMeat( int x, int y )
{
    this->limitX = x;
    this->limitY = y;
}

void Meat::deleteMeat()
{
    scene()->removeItem( this );
    meatscore->addMeatScore(5);
}

void Meat::meatmove()
{
    QList <QGraphicsItem *> collidingList = collidingItems();
    for(size_t i{0}; i < collidingList.size(); ++i)
    {
        if(typeid(*(collidingList)[i])==typeid (SpaceCraft))
         {
           // add score
           meatscore->addMeatScore(1);

           // delete
           scene()->removeItem(this);
           delete this;
           return;
        }
    }

    setPos( x() , y() + 6);
    if( y() >= 700)
    {
        setPos( x(), 700 );
        meatScene->removeItem(this);
        delete this;
    }
}

/* elham zahir */
