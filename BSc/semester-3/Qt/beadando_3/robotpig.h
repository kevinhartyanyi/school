#ifndef ROBOTPIG_H
#define ROBOTPIG_H

#include <QObject>
#include <QDebug>
#include "cord.h"

class robotpig : public QObject
{
    Q_OBJECT
public:
    robotpig(Cord start, Players player, int max, QObject* parent = nullptr);
    void move(Cord next);
    bool fireLaser(Cord enemy);
    bool punch(Cord enemy);    
    void changeDirection(QString direct);
    Cord getCord() {return cord;}
    void damage();
    void changeLife(int life) {this->life = life;}
    Players getPlayer() {return player;}
    int getLife() {return life;}

    
private:
    int life;
    Players player;
    QString direct;
    Cord cord;
    int max;
};

#endif // ROBOTPIG_H
