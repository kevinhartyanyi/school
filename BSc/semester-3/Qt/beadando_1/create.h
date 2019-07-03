#ifndef CREATE_H
#define CREATE_H

#include <QWidget>
#include "size.h"
#include "game.h"

namespace Ui {
class Create;
}

class Create : public QWidget
{
    Q_OBJECT

public:
    explicit Create(QWidget *parent = nullptr);
    ~Create();

private slots:
    void SetTable();
    void NewGame();
    void EndGame();

private:
    Game* play;
    struct size table;
    Ui::Create *ui;
};

#endif // CREATE_H
