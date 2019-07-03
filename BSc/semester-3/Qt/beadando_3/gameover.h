#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class gameover;
}

class gameover : public QDialog
{
    Q_OBJECT

public:
    explicit gameover(QString, QWidget *parent = nullptr);
    ~gameover();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_gameover_rejected();
signals:
    void exitGame();

private:
    Ui::gameover *ui;
};

#endif // GAMEOVER_H
