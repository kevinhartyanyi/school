#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "cord.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int size, int player, Cord currentpos, QWidget *parent = nullptr);
    void setText(QString);
    ~Dialog();
signals:
    void sendText(QString,int,QString,QString,int);

private slots:
    void on_pushButton_clicked();

    void on_Dialog_rejected();

private:
    Ui::Dialog *ui;
    void Send();
    int player;
};

#endif // DIALOG_H
