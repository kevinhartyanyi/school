#ifndef ROBOTPIG_H
#define ROBOTPIG_H

#include <QObject>
#include <QDebug>
#include "cord.h"

class robotpig : public QObject
{
    Q_OBJECT
public:
    robotpig(Cord start, Players player, int max, QObject* parent = nullptr, int life = 3, QString direct = "Up");
    void move(Cord next);
    bool fireLaser(Cord enemy);
    bool punch(Cord enemy);    
    void changeDirection(QString direct);
    Cord getCord() {return cord;}
    void damage();
    void changeLife(int life) {this->life = life;}
    Players getPlayer() {return player;}
    int getLife() {return life;}
    int getMax() {return max;}
    QString getDirect() {return direct;}
    void load(Cord start, Players player, int max, int life, QString direct);



    
private:
    int life;
    Players player;
    QString direct;
    Cord cord;
    int max;
};

#endif // ROBOTPIG_H
