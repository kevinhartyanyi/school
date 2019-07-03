#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class gameOver;
}

class gameOver : public QDialog
{
    Q_OBJECT

public:
    explicit gameOver(QWidget *parent = nullptr);
    void setStat(QString);
    ~gameOver();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::gameOver *ui;
};

#endif // GAMEOVER_H
