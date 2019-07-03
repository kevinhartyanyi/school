#ifndef WARRIOR_H
#define WARRIOR_H
#include <QPushButton>
#include "size.h"


class Warrior : public QPushButton
{
    Q_OBJECT
public:
    explicit Warrior(int player, struct size cord, QWidget * parent = 0);
    struct size Cord() {return cord;}    
    bool attacked;

    void SetPlayer(int player) {this->player = player;}
    void ChangeColour(QString colour);
    void Active(bool active);
    int Player() {return player;}
private:
    int player;
    struct size cord;

};



#endif // WARRIOR_H
