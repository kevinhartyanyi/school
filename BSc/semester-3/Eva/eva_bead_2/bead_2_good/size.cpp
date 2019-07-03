#include "size.h"
#include "ui_size.h"

Size::Size(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Size)
{
    ui->setupUi(this);
    setWindowTitle("Size");
    ui->spinBox->setMinimum(8);
    ui->spinBox->setValue(8);
    ui->comboBox->addItem("Game1.txt");
    ui->comboBox->addItem("Game2.txt");
    ui->comboBox->addItem("Game3.txt");
    ui->comboBox->addItem("Game4.txt");
    ui->comboBox->addItem("Game5.txt");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(go()));
    connect(this,SIGNAL(rejected()),this,SLOT(go()));
}

void Size::go()
{
    if(ui->checkBox->isChecked())
        emit sendLoad(ui->comboBox->currentText());

    emit sendSize(ui->spinBox->value());
    this->close();
}

Size::~Size()
{
    delete ui;
}
