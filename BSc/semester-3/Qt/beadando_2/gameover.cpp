#include "gameover.h"
#include "ui_gameover.h"

gameOver::gameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameOver)
{
    ui->setupUi(this);
    setWindowTitle("Game Over");
}

gameOver::~gameOver()
{
    delete ui;
}

void gameOver::on_pushButton_2_clicked()
{
    emit reject();
    close();
}

void gameOver::setStat(QString over)
{
    ui->label_2->setText("<p align=center><span style= font-size:16pt;>"+over+"</span></p>");
}

void gameOver::on_pushButton_clicked()
{
    emit accept();
    close();
}
