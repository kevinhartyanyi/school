#include "mythread.h"

MyThread::MyThread(QObject* parent) : QThread (parent)
{

}

void MyThread::run()
{
    for(int i = 0; i < 1000; ++i)
    {
        QMutex mutex;
        mutex.lock();
        if(this->Stop) break;
        mutex.unlock();

        emit NumberChanged(i);

        this->msleep(100);
    }
}


