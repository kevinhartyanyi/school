#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mythread.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    MyThread* mthread;
public slots:
    void onNumberChanged(int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
