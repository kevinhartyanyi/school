#ifndef TICTACTOEMODEL_H
#define TICTACTOEMODEL_H

#include <QObject>

class TicTacToeModel : public QObject // a modell típusa
{
    Q_OBJECT
public:
    TicTacToeModel();
    virtual ~TicTacToeModel();
    void newGame(); // új játék kezdése
    void stepGame(int x, int y); // játék léptetése
    int stepNumber() { return _stepNumber; } // lépések számának lekérdezése
    int getField(int x, int y); // játékmező lekérdezése

signals:
    void gameWon(int player); // játékos győzelmének eseménye
    void gameOver(); // döntetlen játék eseménye
    void fieldChanged(int x, int y, int player); // mező változásának eseménye

private: 
    void checkGame(); // játék ellenőrzése

    int _stepNumber; // lépések száma
    int _currentPlayer; // játékos száma
    int** _gameTable; // játéktábla
};

#endif // TICTACTOEMODEL_H
