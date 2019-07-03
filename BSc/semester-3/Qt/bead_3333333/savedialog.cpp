#include "savedialog.h"
#include "ui_savedialog.h"

savedialog::savedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::savedialog)
{
    ui->setupUi(this);
    setWindowTitle("Save");
    setMinimumSize(300,300);
}

savedialog::~savedialog()
{
    delete ui;
}

void savedialog::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    emit saveName(name);
}
