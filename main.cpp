/* AP final project
 * Start: 7 Jul, 2021
 * Space(Chicken) invaders Game
 * Author: Ali(sAm) Mofidan, mahdis mohammadi, elham zahir
*/

#include <QApplication>
#include "View.h"
#include "Menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto menu = new Menu();
    menu->show();

    return a.exec();
}

/* written & directed by sAm mofidian*/
