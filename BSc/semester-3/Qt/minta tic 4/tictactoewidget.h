#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QGridLayout>
#include "tictactoemodel.h"

class TicTacToeWidget : public QWidget // a nézet típusa
{
    Q_OBJECT

public:
    TicTacToeWidget(QWidget *parent = 0);

private slots:
    void buttonClicked(); // táblagombra kattintás esménykezelője
    void newGameButtonClicked(); // új játék gombra kattintás eseménykezelője

    void model_gameWon(int player); // eseménykezelők a modell eseményeire
    void model_gameOver();
    void model_fieldChanged(int x, int y, int player);

private:
    void newGame(); // új játék indítása
    void generateTable(); // tábla létrehozása    

    QGridLayout* _tableLayout;
    QVBoxLayout* _mainLayout;
    QPushButton* _newGameButton; // új játék gombja
    QVector<QVector<QPushButton*> > _gameTableButtons; // gombtábla

    TicTacToeModel _model; // a játékot megvalósító modell
};

#endif // TICTACTOEWIDGET_H
