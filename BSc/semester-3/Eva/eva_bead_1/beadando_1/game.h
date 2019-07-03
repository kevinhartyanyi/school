#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "size.h"
#include "warrior.h"

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(struct size createsize, QWidget *parent = nullptr);

    ~Game();

public slots:
    void ButtonClicked();

private slots:
    void on_actionNew_Game_triggered();
    void on_actionExit_triggered();

signals:
    void StartNewGame();
    void EndGame();

private:
    Ui::Game *ui;
    void NewGame();
    void GenerateTable();
    bool GameOver();
    void UpdateWarriors();
    void CollectWarriors(QVector<Warrior*>& vector, struct size cord, int player);
    bool CollectWarriors(struct size cord, int player);
    void NextTurn();

    QVBoxLayout* mainLayout;
    QGridLayout* boardLayout;
    QVector<QVector<Warrior*>> Table;


    int turn;
    struct size size;
    QLabel* view;
    Warrior* current;
    QWidget* centerWidget;
    QVector<Warrior*> activeWarrior;
    QVector<Warrior*> offenseWarrior;
    QString colour_active   = "background-color: Plum;";
    QString colour_enemy    = "background-color: LightGreen;";
    QString colour_player_1 = "background-color: LightSalmon;";
    QString colour_player_2 = "background-color: Aquamarine;";
    QString colour_neutral  = "background-color: Azure;";

};

#endif // GAME_H
