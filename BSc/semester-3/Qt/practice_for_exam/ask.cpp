#include "ask.h"
#include "ui_ask.h"

Ask::Ask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ask)
{
    ui->setupUi(this);
    setWindowTitle("Suuuuuuuuuuuper");
    setMinimumSize(500,500);
}

Ask::~Ask()
{
    delete ui;
}

void Ask::on_pushButton_clicked()
{
    int s = (ui->lineEdit->text()).toInt();
    qDebug() << "Send " << s;
    emit size(s);
    this->close();
}

void Ask::on_Ask_rejected()
{
    on_pushButton_clicked();
}
