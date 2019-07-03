#include "imagebutton.h"

imageButton::imageButton(Players player, QWidget* parent) : QPushButton(parent)
{
    this->player.load(":/new/img/img/robotpig.png");

    this->direction = "Up";    

    
    if (player == Red) {
        this->setIcon(this->player);
        //rotate(90);
    }
    else if(player == Blue)
    {
        this->setIcon(this->player);
        //rotate(90);
    }
    else {
        this->setStyleSheet("background-color: LightGreen;");
    }

    this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    
}

void imageButton::changeDirection(QString direction)
{


    this->direction = direction;

    if (direction == "Up")
        {
            rotate(-90);
        }
        else if(direction == "Down")
        {
            rotate(90);
        }
        else if (direction == "Left")
        {
            rotate(180);
        }
        else
        {
            rotate(0);
        }

    /*if (direction == "Up")
    {
        if(this->direction == "Down")
            rotate(180);
        else if(this->direction == "Left")
            rotate(90);
        else
            rotate(-90);
    }
    else if(direction == "Down")
    {
        if(this->direction == "Up")
            rotate(180);
        else if(this->direction == "Left")
            rotate(-90);
        else
            rotate(90);
    }
    else if (direction == "Left")
    {
        if(this->direction == "Down")
            rotate(90);
        else if(this->direction == "Right")
            rotate(180);
        else
            rotate(-90);
    }
    else
    {
        if(this->direction == "Down")
            rotate(-90);
        else if(this->direction == "Left")
            rotate(180);
        else
            rotate(90);
    }*/
}

void imageButton::rotate(int rot)
{
    QPixmap pix = this->player;
    QSize size(100,100);
    QMatrix rm;
    rm.rotate(rot);
    pix = this->player.transformed(rm);
    this->setIcon(pix);
    this->setIconSize(size);
}

void imageButton::changePlayers(Players player, QString direction)
{
    QSize size(100,100);
    if (player == Red) {
        changeDirection(direction);
        this->setIconSize(size);
        this->setStyleSheet(red);
    }
    else if(player == Blue)
    {        
        changeDirection(direction);
        this->setIconSize(size);
        this->setStyleSheet(blue);
    }
    else if(player == Neutral)
    {
        this->setIcon(QIcon());
        this->setStyleSheet("background-color: LightGreen;");
    }
    else
    {
        //this->setIcon(QIcon());
        this->setStyleSheet(damage);
    }
}
