#include "tablesize.h"
#include "ui_tablesize.h"

TableSize::TableSize(QWidget *parent) : QDialog(parent), ui(new Ui::TableSize)
{        
    ui->setupUi(this);
    ui->Xspin->setMinimum(4);
    ui->Yspin->setMinimum(3);

    ui->Xspin->setValue(5);
    ui->Yspin->setValue(3);

    setWindowTitle("Choose Size");

    connect(ui->BattleButton,  SIGNAL(clicked()), this, SLOT(SetTable()));
}

void TableSize::SetTable()
{    
    this->table = {ui->Xspin->value(),ui->Yspin->value()};
    QDialog::accept();
    //qDebug() << "Siker";
}


TableSize::~TableSize()
{
    delete ui;
}
