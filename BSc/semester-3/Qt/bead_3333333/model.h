#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QDebug>

#include "robotpig.h"
#include "filecontroller.h"
#include <QStringList>

class model : public QObject
{
    Q_OBJECT
public:
    model(QObject *parent = nullptr);
    void newGame(Cord,Cord,int,QString);
    void step(Cord player1, QString direct1,  QString act1, Cord player2,  QString direct2,  QString act2);
    Cord currentPos(int);
    robotpig* player1;
    robotpig* player2;
    void loadGame(QString);
    void saveGame(QString savename);
    bool getError() {return error;}
    ~model();
signals:
    void Moved(Players,Cord);
    void ChangeDirection(Players, QString);
    void LaserAttack(Players,bool);
    void PunchAttack(Players,bool);
    void GameOver(Players);
    void Error();
    void SendLoad(Cord,Cord,int,int,QString,QString,int);



private:
    void gameOver(Players player);


    FileController* fcont;
    bool exist;
    bool error;

    Cord playerCord1;
    Cord playerCord2;
    
};

#endif // MODEL_H
