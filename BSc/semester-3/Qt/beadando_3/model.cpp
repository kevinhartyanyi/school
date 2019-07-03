#include "model.h"

model::model(QObject* parent) : QObject (parent)
{

}

void model::newGame(Cord startpoint1, Cord startpoint2, int size)
{
    player1 = new robotpig(startpoint1, Red, size, this);
    player2 = new robotpig(startpoint2, Blue, size, this);

    qDebug() << "Red " << player1->getCord().x << " " << player1->getCord().y;
    qDebug() << "Blue " << player2->getCord().x << " " << player2->getCord().y;
    playerCord1 = startpoint1;
    playerCord2 = startpoint2;

}

Cord model::currentPos(int player)
{
    if(player == 1)
        return playerCord1;
    else
        return playerCord2;
}

void model::step(Cord next1,  QString direct1,  QString act1, Cord next2,  QString direct2,  QString act2)
{
    if(next1 != next2)
    {
        player1->move(next1);
        playerCord1 = next1;
        emit Moved(player1->getPlayer(), next1);
        player2->move(next2);
        playerCord2 = next2;
        emit Moved(player2->getPlayer(), next2);
    }
    player1->changeDirection(direct1);
    emit ChangeDirection(player1->getPlayer(), direct1);
    player2->changeDirection(direct2);
    emit ChangeDirection(player2->getPlayer(), direct2);

    if (act1 == "Laser") {
        bool hit = false;
        if (player1->fireLaser(player2->getCord()))
        {
            player2->damage();
            hit = true;
        }
        emit LaserAttack(player1->getPlayer(),hit);
    }
    else if(act1 == "Punch") {
        bool hit = false;
        if (player1->punch(player2->getCord()))
        {
            player2->damage();
            hit = true;
        }
        emit PunchAttack(player1->getPlayer(),hit);
    }

    if (act2 == "Laser") {
        bool hit = false;
        if (player2->fireLaser(player1->getCord()))
        {
            player1->damage();
            hit = true;
        }
        emit LaserAttack(player2->getPlayer(),hit);
    }
    else if(act2 == "Punch") {
        bool hit = false;
        if ( player2->punch(player1->getCord()))
        {
            player1->damage();
            hit = true;
        }
        emit PunchAttack(player2->getPlayer(),hit);
    }

    if(player1->getLife() <= 0)
    {
        gameOver(Red);
    }
    else if(player2->getLife() <= 0)
    {
        gameOver(Blue);
    }
}

void model::gameOver(Players player)
{
    
    if (player == Red) {
        emit GameOver(Blue);
    }
    else {
        emit GameOver(Red);
    }
    
}
model::~model()
{
    delete player1;
    delete player2;
}
