#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mt1;
    mt1.name = "mt1";
    MyThread mt2;
    mt2.name = "mt2";
    MyThread mt3;
    mt3.name = "mt3";

    mt1.start(QThread::HighPriority);
    //mt2.start();
    //mt3.start(QThread::LowPriority);

    mt1.Stop = true;

    return a.exec();
}
