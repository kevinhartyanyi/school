#include <QCoreApplication>
#include "mthead.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    mthead mt;
    mt.start();

    mt.wait();
    qDebug() << "Done";

    return a.exec();
}
