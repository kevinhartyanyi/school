#include "mthead.h"

mthead::mthead(QObject* parent) : QThread (parent)
{

}

void mthead::run()
{
    for(int i = 0; i < 1000; ++i)
    {
        qDebug() << i;
    }
}
