#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QDebug>

#include "robotpig.h"

class model : public QObject
{
    Q_OBJECT
public:
    model(QObject *parent = nullptr);
    void newGame(Cord,Cord,int);
    void step(Cord player1, QString direct1,  QString act1, Cord player2,  QString direct2,  QString act2);
    Cord currentPos(int);
    ~model();
signals:
    void Moved(Players,Cord);
    void ChangeDirection(Players, QString);
    void LaserAttack(Players,bool);
    void PunchAttack(Players,bool);
    void GameOver(Players);


private:
    void gameOver(Players player);

    robotpig* player1;
    robotpig* player2;

    Cord playerCord1;
    Cord playerCord2;
    
};

#endif // MODEL_H
