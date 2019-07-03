#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(int size, int player, Cord currentpos,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Type Command");
    setMinimumSize(500,300);
    this->player = player;
    ui->spinBox->setMinimum(0);
                                //TODO
    ui->spinBox->setMaximum(size);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setText(QString text)
{
    ui->label->setText(text);
}

void Dialog::on_pushButton_clicked()
{
    Send();
    this->close();
}

void Dialog::on_Dialog_rejected()
{
    Send();
}

void Dialog::Send()
{
    QString movedirection = ui->comboBox_2->currentText();
    int move = ui->spinBox->value();
    QString changedirection = ui->comboBox->currentText();
    QString Attack;
    if(ui->LaserButton->isChecked())
        Attack = "Laser";
    else
        Attack = "Punch";

    emit sendText(movedirection, move, changedirection, Attack, player);
}
