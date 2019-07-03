#include "dialog.h"
#include "ui_dialog.h"

#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText("Hello everyone");

    ui->checkBox->setChecked(true);

    for(int i = 0; i < 9; ++i)
    {
        ui->comboBox->addItem(QString::number(i) + " item");
    }

    for(int i = 0; i < 9; ++i)
    {
        ui->listWidget->addItem(QString::number(i) + " item");
    }

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList() << "one" << "two");
    AddRoot("hello", "world");
    AddRoot("hello", "world");
    AddRoot("hello", "world");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QMessageBox::information(this, "Title", "Hello");
}



void Dialog::on_pushButton_2_clicked()
{
    //ui->lineEdit->setText("hello world");
    QMessageBox::information(this,"Title",ui->lineEdit->text());
}

void Dialog::on_pushButton_3_clicked()
{
    if(ui->checkBox->isChecked())
    {
        QMessageBox::information(this,"Cats","You like Cats");

    }
    else
    {
        QMessageBox::information(this,"Cats","You dont like Cats");
    }
}

void Dialog::on_pushButton_4_clicked()
{
    if(ui->radioButton->isChecked())
    {
        QMessageBox::information(this,"T",ui->radioButton->text());
    }
    else
    {
        QMessageBox::information(this,"T",ui->radioButton_2->text());
    }

}

void Dialog::on_pushButton_5_clicked()
{
    QMessageBox::information(this, "Yo", ui->comboBox->currentText());
}

void Dialog::on_pushButton_6_clicked()
{
    ui->listWidget->currentItem()->setText("Fuzzy");
    QListWidgetItem* itm = ui->listWidget->currentItem();
    itm->setTextColor(Qt::red);
}

void Dialog::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem* itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,name);
    itm->setText(1,Description);
   // ui->treeWidget->addTopLevelItem(itm);

    AddChild(itm, "one", "hello");
    AddChild(itm, "two","world");
    AddChild(itm, "one", "hello");
    AddChild(itm, "two","world");
}
void Dialog::AddChild(QTreeWidgetItem* parent, QString name, QString Description)
{
    QTreeWidgetItem* itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Description);
    parent->addChild(itm);
}



void Dialog::on_pushButton_7_clicked()
{
    ui->treeWidget->currentItem()->setBackgroundColor(0,Qt::red);
    ui->treeWidget->currentItem()->setBackgroundColor(1,Qt::blue);
}
