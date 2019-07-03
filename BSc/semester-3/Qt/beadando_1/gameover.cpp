#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) : QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);

    setWindowTitle("This is the end");
}

void GameOver::SetTurns(int turns)
{
    //this->turns = turns;
    ui->turn_label->setText("<span style= font-size:20pt;>Number of turns: "+ QString::number(turns)+"</span>");

}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_NewGameButton_clicked()
{
    emit NewGame();
    close();
}

void GameOver::on_ExitGameButton_clicked()
{
    emit EndGame();
    close();
}
