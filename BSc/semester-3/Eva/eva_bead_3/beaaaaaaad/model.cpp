#include "model.h"

model::model(QObject* parent) : QObject (parent)
{
    exist = false;
    error = false;
    fcont = new FileController(this);
}

void model::newGame(Cord startpoint1, Cord startpoint2, int size, QString filename)
{
    if(!exist)
    {
        player1 = new robotpig(startpoint1, Red, size, this);
        player2 = new robotpig(startpoint2, Blue, size, this);
        exist = true;

        qDebug() << "Red " << player1->getCord().x << " " << player1->getCord().y;
        qDebug() << "Blue " << player2->getCord().x << " " << player2->getCord().y;
        playerCord1 = startpoint1;
        playerCord2 = startpoint2;
    }


}

void model::loadGame(QString name)
{
    qDebug() << "Model Load";

    fcont->load(name);
    if(fcont->getError())
    {
        qDebug() << "Hiba";
        error = true;

        emit Error();
    }
    else
    {


    QStringList player1 = fcont->getPlayer1().split(" ");
    QStringList player2 = fcont->getPlayer2().split(" ");
    qDebug() << player1[0] << " " << player1[1] <<
         player1[2] << " " << player1[3] << player1[4] << " " << player1[5];
    Cord c1 = {player1[3].toInt(), player1[4].toInt()};
    Cord c2 = {player2[3].toInt(), player2[4].toInt()};

    QString d1 = player1[2];
    QString d2 = player2[2];



    qDebug() << "Model Load2";

    if(!exist)
    {
        qDebug() << c1.x << " " << c1.y;
        this->player1 = new robotpig({1,1}, Red, 2, this);
        this->player2 = new robotpig({1,1}, Blue, 2, this);
        exist = true;
        qDebug() << "Model Load4";
    }

    this->player1->load(c1, Red, player1[5].toInt() ,player1[0].toInt(),d1);
    this->player2->load(c2, Blue, player2[5].toInt() ,player2[0].toInt(),d2);

    playerCord1 = c1;
    playerCord2 = c2;

    qDebug() << "Sending Load Data";
    emit SendLoad(c1,c2,player1[0].toInt(),player2[0].toInt(),d1,d2,player1[5].toInt());
    }

}



void model::saveGame(QString savename)
{
    qDebug() << "Save Game";
    QString p1 = "Red";
    QString p2 = "Blue";
    fcont->save(savename, player1->getLife(), p1,
               player1->getDirect(), player1->getCord(), player1->getMax(),
               player2->getLife(), p2,
                 player2->getDirect(), player2->getCord(), player2->getMax());

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
    delete fcont;
}
