#include "tictactoewidget.h"
#include <QMessageBox>

TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(400, 400);
    setBaseSize(400,400);
    setWindowTitle(tr("Tic-Tac-Toe"));

    _newGameButton = new QPushButton(trUtf8("Új játék")); // új játék gomb
    connect(_newGameButton, SIGNAL(clicked()), this, SLOT(newGameButtonClicked()));

    _mainLayout = new QVBoxLayout(); // vertikális elhelyezkedés a teljes felületnek
    _mainLayout->addWidget(_newGameButton);

    _tableLayout = new QGridLayout(); // rácsos elhelyezkedés a játékmezőnek
    _mainLayout->addLayout(_tableLayout);
    generateTable();

    setLayout(_mainLayout);

    // modell eseményeinek feldolgozása
    connect(&_model, SIGNAL(gameWon(int)), this, SLOT(model_gameWon(int)));
    connect(&_model, SIGNAL(gameOver()), this, SLOT(model_gameOver()));
    connect(&_model, SIGNAL(fieldChanged(int, int, int)), this, SLOT(model_fieldChanged(int, int, int)));

    _model.newGame(); // új játék indítása
}

void TicTacToeWidget::newGame()
{
    _model.newGame();

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            _gameTableButtons[i][j]->setEnabled(true);
            _gameTableButtons[i][j]->setText("");
        }
    }
}

void TicTacToeWidget::generateTable()
{
    _gameTableButtons.resize(3);

    for (int i = 0; i < 3; ++i)
    {
        _gameTableButtons[i].resize(3);
        for (int j = 0; j < 3; ++j)
        {
            _gameTableButtons[i][j]= new QPushButton(this);
            _gameTableButtons[i][j]->setText("");
            _gameTableButtons[i][j]->setFont(QFont("Times New Roman", 100, QFont::Bold));
            _gameTableButtons[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            _tableLayout->addWidget(_gameTableButtons[i][j], i, j); // gombok felvétele az elhelyezésbe

            connect(_gameTableButtons[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }
}

void TicTacToeWidget::buttonClicked()
{
    QPushButton* senderButton = dynamic_cast <QPushButton*> (QObject::sender());
    int location = _tableLayout->indexOf(senderButton);

    int x = location / 3;
    int y = location % 3;
    _model.stepGame(x, y); // játék léptetése
}

void TicTacToeWidget::newGameButtonClicked()
{
    newGame();
}

void TicTacToeWidget::model_gameWon(int player)
{
    if (player == 1) // az eredmény függvényében jelenítjük meg a győztest
    {
        QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("Az X nyerte a játékot!"));
        newGame();
    }
    else
    {
        QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("A O nyerte a játékot!"));
        newGame();
    }
}

void TicTacToeWidget::model_gameOver()
{
    QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("A játék döntetlen lett!"));
    _model.newGame();
}

void TicTacToeWidget::model_fieldChanged(int x, int y, int player)
{
    if (player == 1)
        _gameTableButtons[x][y]->setText("X");
    else
        _gameTableButtons[x][y]->setText("0");
    _gameTableButtons[x][y]->setEnabled(false);
}
