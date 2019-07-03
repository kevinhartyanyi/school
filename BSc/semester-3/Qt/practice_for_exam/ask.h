#ifndef ASK_H
#define ASK_H

#include <QDialog>
#include <QtDebug>

namespace Ui {
class Ask;
}

class Ask : public QDialog
{
    Q_OBJECT

public:
    explicit Ask(QWidget *parent = nullptr);
    ~Ask();

signals:
    void size(int);

private slots:
    void on_pushButton_clicked();

    void on_Ask_rejected();

private:
    Ui::Ask *ui;
};

#endif // ASK_H
