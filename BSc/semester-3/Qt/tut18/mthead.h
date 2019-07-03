#ifndef MTHEAD_H
#define MTHEAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class mthead : public QThread
{
    Q_OBJECT
public:
    mthead(QObject* parent = 0);
    void run();
};

#endif // MTHEAD_H
