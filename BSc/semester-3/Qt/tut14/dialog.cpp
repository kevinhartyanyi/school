#include "dialog.h"
#include "ui_dialog.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //info
    QMessageBox::information(this,"Title","Text");
}

void Dialog::on_pushButton_2_clicked()
{
    //question
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Title","Do you like cats?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        QMessageBox::information(this,"Title","Gooooood");
    }
    else
    {
        QMessageBox::information(this,"Title","Baaaaaad");
    }
}

void Dialog::on_pushButton_3_clicked()
{
    QMessageBox::warning(this,"Title","Text");
}

void Dialog::on_pushButton_4_clicked()
{
    QMessageBox::question(this,"My Title", "My Text", QMessageBox::YesToAll | QMessageBox::Yes | QMessageBox::No | QMessageBox::NoAll);
}
