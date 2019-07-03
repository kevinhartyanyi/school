#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class TicTacToeWidget : public QWidget // játékot megjelenítő ablak
{
    Q_OBJECT

public:
    TicTacToeWidget(QWidget *parent = 0);

private slots:
    void buttonClicked(); // táblagombra kattintás esménykezelője
    void newGameButtonClicked(); // új játék gombra kattintás eseménykezelője

private:
    void newGame(); // új játék kezdése
    void stepGame(int x, int y); // játék léptetése
    void generateTable(); // tábla létrehozása
    void checkGame(); // vége van-e a játéknak

    int stepCount; // lépések száma
    int playerNr; // játékos száma
    QGridLayout* tableLayout;
    QVBoxLayout* mainLayout;
    QPushButton* newGameButton; // új játék gombja
    QVector<QVector<QPushButton*> > buttonTable; // gombtábla
    int** gameTable; // játéktábla
};

#endif // TICTACTOEWIDGET_H
