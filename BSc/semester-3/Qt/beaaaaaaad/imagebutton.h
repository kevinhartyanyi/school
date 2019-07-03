#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QPushButton>
#include "cord.h"

class imageButton : public QPushButton
{
    Q_OBJECT
public:
    imageButton(Players player, QWidget* parent = nullptr);
    void changePlayers(Players player,QString);
    void changeDirection(QString direction);
private:
    void rotate(int);
    QPixmap player;
    QString damage = "background-color: LightSalmon;";
    QString red = "background-color: Coral;";
    QString blue = "background-color: DeepSkyBlue;";
    QString direction;

};

#endif // IMAGEBUTTON_H
