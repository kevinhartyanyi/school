#include "size.h"
#include "ui_size.h"

Size::Size(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Size)
{
    ui->setupUi(this);
    setWindowTitle("Size");
    ui->spinBox->setMinimum(4);
    ui->spinBox->setValue(5);    
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(go()));
    connect(this,SIGNAL(rejected()),this,SLOT(go()));
}

void Size::go()
{
    if(ui->checkBox->isChecked())
        emit sendLoad(ui->lineEdit->text());
    else
        emit sendSize(ui->spinBox->value());

    this->close();
}

Size::~Size()
{
    delete ui;
}
