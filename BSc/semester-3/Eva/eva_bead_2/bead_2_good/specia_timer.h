#ifndef SPECIA_TIMER_H
#define SPECIA_TIMER_H

#include <QTimer>

class specia_timer : public QTimer
{
    Q_OBJECT
public:
    specia_timer(int cord, int ms, QString direction, QObject *parent = nullptr);
    void changeCord(int);
    int getCord();
    int getRandomTime();
    QString getDirection();
    void setDirection(QString);

signals:
    void time_out();

private slots:
    void send_time_out();

private:
    int cord;
    int time;
    QString direction;

};

#endif // SPECIA_TIMER_H
