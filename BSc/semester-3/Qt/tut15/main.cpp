#include <QCoreApplication>
#include "mytimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTimer mytimer;

    return a.exec();
}
