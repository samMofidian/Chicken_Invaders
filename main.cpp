#include <QApplication>
#include "View.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto myView = new View();
    myView->show();

    return a.exec();
}
