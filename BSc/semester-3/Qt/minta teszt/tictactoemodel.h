#ifndef TICTACTOEMODEL_H
#define TICTACTOEMODEL_H

#include <QObject>


class TicTacToeModel : public QObject // a modell típusa
{
    Q_OBJECT
public:
    enum Player { NoPlayer, PlayerX, PlayerO }; // játékos felsorolási típusa

    TicTacToeModel();
    virtual ~TicTacToeModel();
    void newGame(); // új játék kezdése
    void stepGame(int x, int y); // játék léptetése
    int stepNumber() { return _stepNumber; } // lépések számának lekérdezése
    Player getField(int x, int y); // játékmező lekérdezése

signals:
    void gameWon(TicTacToeModel::Player player); // játékos győzelmének eseménye
    void gameOver(); // döntetlen játék eseménye
    void fieldChanged(int x, int y, TicTacToeModel::Player player); // mező változásának eseménye

private: 
    void checkGame(); // játék ellenőrzése

    int _stepNumber; // lépések száma
    Player _currentPlayer; // játékos száma
    Player** _gameTable; // játéktábla
};

#endif // TICTACTOEMODEL_H
