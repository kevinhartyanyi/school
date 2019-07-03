#include "create.h"
#include "ui_create.h"

Create::Create(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Create)
{
    ui->setupUi(this);
    ui->Xspin->setMinimum(4);
    ui->Yspin->setMinimum(3);

    ui->Xspin->setValue(5);
    ui->Yspin->setValue(3);

    setWindowTitle("Choose Size");

    connect(ui->BattleButton,  SIGNAL(clicked()), this, SLOT(SetTable()));
}

void Create::SetTable()
{
    this->table = {ui->Xspin->value(),ui->Yspin->value()};
    play = new Game(table);
    connect(play, SIGNAL(StartNewGame()), this, SLOT(NewGame()));
    connect(play, SIGNAL(EndGame()), this, SLOT(EndGame()));
    play->show();

    this->hide();
}

void Create::NewGame()
{
    delete play;
    this->show();
}

void Create::EndGame()
{
    delete play;
    close(); //mi a különbség ehhez képest destroy(true); ?
}

Create::~Create()
{
    delete ui;
}
