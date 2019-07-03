#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();
    void SetTurns(int turns);

signals:
    void NewGame();
    void EndGame();

private slots:
    void on_NewGameButton_clicked();

    void on_ExitGameButton_clicked();


private:
    int turns;
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
