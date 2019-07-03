#include "tictactoemodel.h"

TicTacToeModel::TicTacToeModel()
{
    _gameTable = new int*[3];
    for (int i = 0; i < 3; ++i)
    {
        _gameTable[i] = new int[3];
    }
}

TicTacToeModel::~TicTacToeModel()
{
    delete[] _gameTable;
}

void TicTacToeModel::newGame()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            _gameTable[i][j] = 0; // a játékosok pozícióit töröljük
        }

    _stepNumber = 0;
    _currentPlayer = 1; // először az X lép
}

void TicTacToeModel::stepGame(int x, int y)
{
    if (_stepNumber >= 9) // ellenőrizzük a lépésszámot
        return;
    if (x < 0 || x > 2 || y < 0 || y > 2) // ellenőrizzük a tartomány
        return;
    if (_gameTable[x][y] != 0) // ellenőrizzük a mezőt
        return;

    _gameTable[x][y] = _currentPlayer; // pozíció rögzítése
    fieldChanged(x, y, _currentPlayer); // jelezzük egy eseménykiváltással, hogy változott a mező

    _stepNumber++;
    _currentPlayer = _currentPlayer % 2 + 1;

    checkGame();
}

void TicTacToeModel::checkGame()
{
    int won = 0;

    for(int i = 0; i < 3; ++i) // ellenőrzések végrehajtása
    {
        if (_gameTable[i][0] != 0 && _gameTable[i][0] == _gameTable[i][1] && _gameTable[i][1] == _gameTable[i][2])
            won = _gameTable[i][0];
    }
    for(int i = 0; i < 3; ++i)
    {
        if (_gameTable[0][i] != 0 && _gameTable[0][i] == _gameTable[1][i] && _gameTable[1][i] == _gameTable[2][i])
            won = _gameTable[0][i];
    }
    if (_gameTable[0][0] != 0 && _gameTable[0][0] == _gameTable[1][1] && _gameTable[1][1] == _gameTable[2][2])
        won = _gameTable[0][0];
    if (_gameTable[0][2] != 0 && _gameTable[0][2] == _gameTable[1][1] && _gameTable[1][1] == _gameTable[2][0])
        won = _gameTable[0][2];

    if (won > 0) // ha valaki győzött
    {
        gameWon(won); // esemény kiváltása
    }
    else if (_stepNumber == 9) // döntetlen játék
    {
        gameOver(); // esemény kiváltása
    }
}

int TicTacToeModel::getField(int x, int y)
{
    if (x < 0 || x > 2 || y < 0 || y > 2) // ellenőrizzük a tartomány
        return 0;

    return _gameTable[x][y];
}
