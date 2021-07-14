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

    // set win (start random level)
    if( lvl == 1 )
    {
        Bullet::setNum(0);
        SpaceCraft::setShotType(1);
    }
    if( lvl == 2 )
    {
        Bullet::setNum(20);
        SpaceCraft::setShotType(1);
    }
    if( lvl == 3 )
    {
        Bullet::setNum(56);
        SpaceCraft::setShotType(1);
    }
    if( lvl == 4 )
    {
        Bullet::setNum(80);
        SpaceCraft::setShotType(1);
    }
    if( lvl == 5 )
    {
        Bullet::setNum(110);
        SpaceCraft::setShotType(1);
    }
    if( lvl == 6 )
    {
        Bullet::setNum(128);
        SpaceCraft::setShotType(1);
    }


    /* elham zahir */
    // meat
    if( lvl >= 3 )
    {
        meatscore = new MeatScore();
        scene->addItem(meatscore);
        meatscore->setPos(140, 660);
    }
    /* elham zahir */

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

/* elham zahir */
void Controller::addChick()
{
    if( lvl == 1 )
    {
        Chicken *** chicken = new Chicken**[5];
        for( int i = 0 ; i < 5 ; i ++ )
        {
            chicken[i] = new Chicken*[4];
            for( int j = 0 ; j < 4 ; j ++ )
            {
                chicken[i][j] = new Chicken{scene, holder,1 ,score, ctimer,  350 - 100 * j };
                int a = 150 * i + 250;
                chicken[i][j]->setPos( a, - 100 * j - 600 );
                chicken[i][j]->move();
            }
        }
    }

    if( lvl == 2 )
    {
        Chicken *** chicken = new Chicken**[9];
        for( int i = 0 ; i < 9 ; i ++ )
        {
            chicken[i] = new Chicken*[4];
            for( int j = 0 ; j < 4 ; j ++ )
            {
                chicken[i][j] = new Chicken{scene, holder,1 ,score, ctimer,  350 - 100 * j };
                int a = 120 * i + 90;
                chicken[i][j]->setPos( a, - 100 * j - 600 );
                chicken[i][j]->move();
            }
        }
    }

    if( lvl == 3 )
    {
        Hen *** hen = new Hen**[4];
        Chicken *** chicken = new Chicken**[4];
        for( int i = 0 ; i < 4 ; i ++ )
        {
            hen[i] = new Hen*[3];
            for( int j = 0 ; j < 3 ; j ++ )
            {
                hen[i][j] = new Hen{scene, holder,2 ,score,ctimer,  250 - 100 * j };
                int a = 240 * i + 120;
                if( j % 2 == 0 )
                    a += 120;
                hen[i][j]->setPos( a , - 100 * j - 600 );
                int x = hen[i][j]->x();
                int y = hen[i][j]->y();
                if( hen[i][j]->exist() == false )
                {
                    Meat * meat = new Meat{ scene, ctimer, meatscore, x, y, holder };
                }
            }
        }

        for( int i = 0 ; i < 4 ; i ++ )
        {
            chicken[i] = new Chicken*[3];
            for( int j = 0 ; j < 3 ; j ++ )
            {
                chicken[i][j] = new Chicken{scene, holder,1 , score, ctimer,  250 - 100 * j };
                int a = 240 * i + 120;
                if( j % 2 == 1 )
                    a += 120;
                chicken[i][j]->setPos( a , - 100 * j - 600 );
                chicken[i][j]->move();
            }
         }
     }

    if( lvl == 4 )
    {
        Chicken *** chicken = new Chicken**[4];
        for( int i = 0 ; i < 4 ; i ++ )
        {
            chicken[i] = new Chicken*[3];
            for( int j = 0 ; j < 3 ; j ++ )
            {
                chicken[i][j] = new Chicken{scene, holder,1 , score, ctimer, 250 - 100 * j };
                int a = 320 * i + 90;
                chicken[i][j]->setPos( a, - 100 * j - 600 );
                chicken[i][j]->move();
            }
         }
         Hen *** hen1 = new Hen**[3];
        for( int i = 0 ; i < 3 ; i ++ )
        {
            hen1[i] = new Hen*[3];
            for( int j = 0 ; j < 3 ; j ++ )
            {
                hen1[i][j] = new Hen{scene, holder, 2, score, ctimer, 250 - 100 * j };
                int a = 320 * i + 200;
                hen1[i][j]->setPos( a , - 100 * j - 600 );
                int x = hen1[i][j]->x();
                int y = hen1[i][j]->y();
                if( hen1[i][j]->exist() == false )
                {
                    Meat * meat = new Meat{ scene, ctimer, meatscore, x, y, holder };
                }
             }
         }
         Hen *** hen2 = new Hen**[3];
          for( int i = 0 ; i < 3 ; i ++ )
          {
                hen2[i] = new Hen*[3];
                for( int j = 0 ; j < 3 ; j ++ )
                {
                    hen2[i][j] = new Hen{scene, holder, 2, score, ctimer, 250 - 100 * j };
                    int a = 320 * i + 300;
                    hen2[i][j]->setPos( a , - 100 * j - 600 );
                    int x = hen2[i][j]->x();
                    int y = hen2[i][j]->y();
                    hen2[i][j]->henmove();
                    if( hen2[i][j]->exist() == false )
                    {
                        Meat * meat = new Meat{ scene, ctimer, meatscore, x, y, holder };
                    }
                }
           }
      }

    if( lvl == 5 )
    {
        Superhen *** superhen = new Superhen**[3];
        for( int i = 0 ; i < 3 ; i ++ )
        {
            superhen[i] = new Superhen*[3];
            for( int j = 0 ; j < 3 ; j ++ )
            {
                superhen[i][j] = new Superhen{scene, holder,4 ,score, ctimer, 250 - 100 * j };
                int k;
                if( j % 2 == 0 )
                    k = 60;
                else
                    k = - 60;
                int a = 240 * i + 280;
                superhen[i][j]->setPos( a + k , - 100 * j - 600 );
                int x = superhen[i][j]->x();
                int y = superhen[i][j]->y();
                superhen[i][j]->superhenmove();
                if( superhen[i][j]->exist() == false )
                {
                    Meat * meat = new Meat{ scene, ctimer, meatscore, x, y, holder };
                }
            }
         }
         Hen *** hen = new Hen**[3];
         for( int i = 0 ; i < 3 ; i ++ )
         {
                hen[i] = new Hen*[3];
                for( int j = 0 ; j < 3 ; j ++ )
                {
                   hen[i][j] = new Hen{scene, holder,3 ,score, ctimer, 250 - 100 * j };
                   int k;
                   if( j % 2 == 1 )
                       k = 60;
                   else
                       k = - 60;
                   int a = 240 * i + 280;
                   hen[i][j]->setPos( a + k , - 100 * j - 600 );
                   int x = hen[i][j]->x();
                   int y = hen[i][j]->y();
                   hen[i][j]->henmove();
                   if( hen[i][j]->exist() == false )
                   {
                        Meat * meat = new Meat{ scene, ctimer, meatscore, x, y, holder };
                   }
                }
          }
    }

//    if( lvl == 6 )
//    {
//        Superhen *** superhen = new Superhen**[9];
//        for( int i = 0 ; i < 9 ; i ++ )
//        {
//            superhen[i] = new Superhen*[3];
//            for( int j = 0 ; j < 3 ; j ++ )
//            {
//                superhen[i][j] = new Superhen{scene, holder,4 ,score, ctimer, 250 - 100 * j };
//                int a = 120 * i + 90;
//                superhen[i][j]->setPos( a , - 100 * j - 600 );
//                if( superhen[i][j]->y() != 100 * j )
//                {
//                    superhen[i][j]->setPos( superhen[i][j]->x(), superhen[i][j]->y() + 6 );
//                }
//            }
//         }
//    }

    if( lvl == 6 )
    {
        Superhen *** superhen = new Superhen**[9];
        //Meat *** meat = new Meat**[9];
        for( int i = 0 ; i < 9 ; i ++ )
        {
            superhen[i] = new Superhen*[3];
            //meat[i] = new Meat*[3];
            for( int j = 0 ; j < 3 ; j ++ )
            {
                superhen[i][j] = new Superhen{scene, holder,4 , score, ctimer, 250 - 100 * j };
                int a = 120 * i + 120;
                superhen[i][j]->setPos( a , - 100 * j - 600 );
                superhen[i][j]->superhenmove();
                int x = superhen[i][j]->x();
                int y = superhen[i][j]->y();
                if( superhen[i][j]->exist() == true )
                {
                       Meat * meat = new Meat{ scene, ctimer, meatscore, x, y, holder };
                }
             }
         }
    }

}
/* elham zahir */

/* sAm mofidian, elham zahir */
bool Controller::checkWin()
{
    // 20
    if( Bullet::numberOfChickens == 20 && lvl == 1 )
    {
        return true;
    }
    // 20 + 36
    else if( Bullet::numberOfChickens == 56 && lvl == 2 )
    {
        return true;
    }
    // 20 + 36 + 24
    else if( Bullet::numberOfChickens == 80 && lvl == 3 )
    {
        return true;
    }
    // 20 + 36 + 24 + 30
    else if( Bullet::numberOfChickens == 110 && lvl == 4 )
    {
        return true;
    }
    // 20 + 36 + 24 + 30 + 18
    else if( Bullet::numberOfChickens == 128 && lvl == 5 )
    {
        return true;
    }
    // 20 + 36 + 24 + 30 + 18 + 27
    else if( Bullet::numberOfChickens == 155 && lvl == 6 )
    {
        return true;
    }

    return false;
}
/* sAm mofidian, elham zahir */

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}

/* written & directed by sAm mofidian */

