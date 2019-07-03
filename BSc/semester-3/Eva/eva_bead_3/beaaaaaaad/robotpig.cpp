#include "robotpig.h"


robotpig::robotpig(Cord start, Players player, int max, QObject* parent, int life, QString direct) : QObject (parent)
{
    this->player = player;
    cord = start;
    this->direct = direct;
    this->max = max;
    this->life = life;
}

void robotpig::load(Cord start, Players player, int max, int life, QString direct)
{
    this->player = player;
    cord = start;
    this->direct = direct;
    this->max = max;
    this->life = life;
    qDebug() << "Robot";
}

void robotpig::changeDirection(QString direct)
{
    this->direct = direct;
}

void robotpig::move(Cord next)
{
    this->cord = next;

}

bool robotpig::fireLaser(Cord enemy)
{
    if(direct == "Up")
        return (cord.x > enemy.x && cord.y == enemy.y);
    else if(direct == "Down")
        return (cord.x < enemy.x && cord.y == enemy.y);
    else if(direct == "Left")
        return (cord.x == enemy.x && cord.y > enemy.y);
    else
        return (cord.x == enemy.x && cord.y < enemy.y);
    

}

bool robotpig::punch(Cord enemy)
{
    qDebug() << cord.x << " " <<cord.y << "      " <<enemy.x << " " <<enemy.y << "  max: " <<max;
    for(int i = cord.x-1; i <= cord.x+1; i++)
    {
        if(i < 0 || i > max)
            continue;
                
        for(int j = cord.y-1; j <= cord.y+1; j++)
        {            
            if(j < 0 || j > max)
                continue;
            qDebug() << "Try: " << i << " " << j;
            if (i == enemy.x && j == enemy.y) {
                return true;
            }            
        }        
    }
    return false;
    
}

void robotpig::damage()
{
    --life;

}




