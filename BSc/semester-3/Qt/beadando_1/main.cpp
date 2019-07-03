#include "create.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Game* w = new Game;
    //w->show();
    Create* c = new Create;
    c->show();


    return a.exec();
}
