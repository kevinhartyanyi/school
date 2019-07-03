#include "specia_timer.h"

specia_timer::specia_timer(int cord, int ms, QString direction, QObject *parent) : QTimer(parent)
{
    this->cord = cord;
    this->direction = direction;
    this->time = ms;

    connect(this, SIGNAL(timeout()), this, SLOT(send_time_out()));
    start(ms);
}

int specia_timer::getRandomTime()
{
    return time;
}

void specia_timer::changeCord(int cord)
{
    this->cord = cord;
}

int specia_timer::getCord()
{
    return cord;
}

void specia_timer::send_time_out()
{
    emit time_out();
}

QString specia_timer::getDirection()
{
    return direction;
}

void specia_timer::setDirection(QString direction)
{
    this->direction = direction;
}
