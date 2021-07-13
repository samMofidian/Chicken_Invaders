/* written & directed by sAm mofidian */
#include "Controller.h"
#include "SpaceCraft.h"

Controller::Controller(int season, int lvl, QObject *parent) : QObject(parent)
{
    // init season
    this->season = season;

    /* elham zahir */
    // init lvl
    this->lvl = lvl;
    /* elham zahir */

    // scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1200, 750);

    // holder
    holder = new QGraphicsRectItem();
    holder->setRect(0, 0, 1200, 750);

    // score
    score = new Score();
    scene->addItem(score);
    score->setPos(30, 10);

    // timer
    ctimer = new QTimer();
    ctimer->start(40);

}

void Controller::addSpaceCraft()
{
    spaceCraft = new SpaceCraft{scene, holder};
    // focus
    spaceCraft->setFlag(QGraphicsItem::ItemIsFocusable);
    spaceCraft->setFocus();

    // life
    life = new Life(spaceCraft);
    scene->addItem(life);
    life->setPos(55, 660);
}

void Controller::addGift()
{
    giftList.push_back(new Gift{scene, ctimer, holder});
}

void Controller::addEgg()
{
    eggList.push_back(new Egg{scene, ctimer, score, holder});
}


bool Controller::game_over()
{
    if (spaceCraft->getLives() < 1)
        return true;

    return false;
}

void Controller::addChick()
{

    if( lvl == 1 ){
                Chicken *** chicken = new Chicken**[5];
                for( int i = 0 ; i < 5 ; i ++ ){
                    chicken[i] = new Chicken*[4];
                    for( int j = 0 ; j < 4 ; j ++ ){
                    chicken[i][j] = new Chicken{scene, holder,1 , score, ctimer};
                    int a = 150 * i + 250;
                   chicken[i][j]->setPos( a, - 100 * j - 600 );
                   if( chicken[i][0]->y() <= 300 ){
                   chicken[i][j]->setPos( chicken[i][j]->x(), chicken[i][j]->y() + 6 );
                   //chicken[i][0]->move();
                }
                    }
                }
        }

    if( lvl == 2 ){
                Chicken *** chicken = new Chicken**[9];
                for( int i = 0 ; i < 9 ; i ++ ){
                    chicken[i] = new Chicken*[4];
                    for( int j = 0 ; j < 4 ; j ++ ){
                    chicken[i][j] = new Chicken{scene, holder,1 , score, ctimer};
                    int a = 120 * i + 90;
                   chicken[i][j]->setPos( a, - 100 * j - 600 );
                   if( chicken[i][j]->y() != 300 ){
                   chicken[i][j]->setPos( chicken[i][j]->x(), chicken[i][j]->y() + 6 );
                }
                }
            }
            }
            if( lvl == 3 ){
            Hen *** hen = new Hen**[4];
            Chicken *** chicken = new Chicken**[4];
            for( int i = 0 ; i < 4 ; i ++ ){
                hen[i] = new Hen*[3];
                for( int j = 0 ; j < 3 ; j ++ ){
                hen[i][j] = new Hen{scene, holder,2 , score, ctimer};
                int a = 240 * i + 120;
                if( j % 2 == 0 )
                    a += 120;
                hen[i][j]->setPos( a , - 100 * j - 600 );
                }
            }
            for( int i = 0 ; i < 4 ; i ++ ){
                chicken[i] = new Chicken*[3];
                for( int j = 0 ; j < 3 ; j ++ ){
                chicken[i][j] = new Chicken{scene, holder,1 , score, ctimer};
                int a = 240 * i + 120;
                if( j % 2 == 1 )
                    a += 120;
                chicken[i][j]->setPos( a , - 100 * j - 600 );
                }
               }
              }
            if( lvl == 4 ){
                Hen *** hen = new Hen**[10];
                for( int i = 0 ; i < 10 ; i ++ ){
                    hen[i] = new Hen*[3];
                    for( int j = 0 ; j < 3 ; j ++ ){
                    hen[i][j] = new Hen{scene, holder,2 , score, ctimer};
                    int a = 100 * i + 80;
                   hen[i][j]->setPos( a , - 100 * j - 600 );
                   if( hen[i][j]->y() != 100 * j ){
                   hen[i][j]->setPos( hen[i][j]->x(), hen[i][j]->y() + 6 );
                }
                }
                }
            }
            if( lvl == 5 ){
                Superhen *** superhen = new Superhen**[3];
                for( int i = 0 ; i < 3 ; i ++ ){
                    superhen[i] = new Superhen*[3];
                    for( int j = 0 ; j < 3 ; j ++ ){
                    superhen[i][j] = new Superhen{scene, holder,4 , score, ctimer};
                    int k;
                    if( j % 2 == 0 )
                        k = 60;
                    else
                        k = - 60;
                    int a = 240 * i + 280;
                   superhen[i][j]->setPos( a + k , - 100 * j - 600 );
                    }
                }
                   Hen *** hen = new Hen**[3];
                   for( int i = 0 ; i < 3 ; i ++ ){
                       hen[i] = new Hen*[3];
                       for( int j = 0 ; j < 3 ; j ++ ){
                       hen[i][j] = new Hen{scene, holder,3 , score, ctimer};
                       int k;
                       if( j % 2 == 1 )
                           k = 60;
                       else
                           k = - 60;
                       int a = 240 * i + 280;
                      hen[i][j]->setPos( a + k , - 100 * j - 600 );}}}

    if( lvl == 6 ){
                Superhen *** superhen = new Superhen**[9];
                for( int i = 0 ; i < 9 ; i ++ ){
                    superhen[i] = new Superhen*[3];
                    for( int j = 0 ; j < 3 ; j ++ ){
                    superhen[i][j] = new Superhen{scene, holder,4, score , ctimer};
                    int a = 120 * i + 90;
                   superhen[i][j]->setPos( a , - 100 * j - 600 );
                   if( superhen[i][j]->y() != 100 * j ){
                   superhen[i][j]->setPos( superhen[i][j]->x(), superhen[i][j]->y() + 6 );
                }
                }
                }
            }
}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}


