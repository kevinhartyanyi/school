#include "gameover.h"
#include "ui_gameover.h"

gameover::gameover(QString winner, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
    setWindowTitle("Game Over");
    setMinimumSize(500,500);
    ui->label->setText("<p><span style= font-size:14pt;>"+winner+"</span></p>");
}

gameover::~gameover()
{
    delete ui;
}

void gameover::on_pushButton_clicked()
{
    emit newGame();
    close();
}

void gameover::on_pushButton_2_clicked()
{
    emit exitGame();
    close();
}

void gameover::on_gameover_rejected()
{
    on_pushButton_2_clicked();
}
