#include "warrior.h"

Warrior::Warrior(int player, struct size cord, QWidget *parent) : QPushButton (parent)
{
    this->cord = cord;
    this->attacked = false;

    if(player == 1)
    {
        this->player = 1;
        //QPixmap img(":/img/resources/red.jpg");
        //setIcon(img);
        setStyleSheet("background-color: LightSalmon;");
        setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        //setIconSize(img.rect().size());

    }
    else if(player == 2)
    {
        this->player = 2;
        //QPixmap img(":/img/resources/blue.jpg");
        //setIcon(img);
        setStyleSheet("background-color: Aquamarine;");
        setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        //setIconSize(img.rect().size());

    }
    else
    {
        this->player = 0;
        setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        setStyleSheet("background-color: Azure;");
    }

    setEnabled(false);
}

void Warrior::ChangeColour(QString colour)
{
    setStyleSheet(colour);
}

void Warrior::Active(bool active)
{
    setEnabled(active);
}

