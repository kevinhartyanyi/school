#include "tictactoewidget.h"
#include <QMessageBox>

TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(400, 400);
    setBaseSize(400,400);
    setWindowTitle(tr("Tic-Tac-Toe"));

    newGameButton = new QPushButton(trUtf8("Új játék")); // új játék gomb
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(newGameButtonClicked()));

    mainLayout = new QVBoxLayout(); // vertikális elhelyezkedés a teljes felületnek
    mainLayout->addWidget(newGameButton);

    tableLayout = new QGridLayout(); // rácsos elhelyezkedés a játékmezőnek
    generateTable();

    mainLayout->addLayout(tableLayout);
    setLayout(mainLayout);

    newGame();
}

void TicTacToeWidget::newGame()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            gameTable[i][j] = 0; // a játékosok pozícióit töröljük
            buttonTable[i][j]->setText(""); // a szöveget töröljük
            buttonTable[i][j]->setEnabled(true); // bekapcsoljuk a gombot
        }

    stepCount = 0;
    playerNr = 1; // először az X lép
}

void TicTacToeWidget::stepGame(int x, int y)
{
    gameTable[x][y] = playerNr; // pozíció rögzítése

    if (playerNr == 1)
        buttonTable[x][y]->setText("X"); // megjelenítés a gombon
    else
        buttonTable[x][y]->setText("0");
    buttonTable[x][y]->setEnabled(false);

    stepCount++;
    playerNr = playerNr % 2 + 1;

    checkGame();
}

void TicTacToeWidget::generateTable()
{
    gameTable = new int*[3];
    buttonTable.resize(3);

    for (int i = 0; i < 3; ++i)
    {
        gameTable[i] = new int[3];
        buttonTable[i].resize(3);
        for (int j = 0; j < 3; ++j)
        {
            buttonTable[i][j]= new QPushButton(this);
            buttonTable[i][j]->setFont(QFont("Times New Roman", 100, QFont::Bold));
            buttonTable[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            tableLayout->addWidget(buttonTable[i][j], i, j); // gombok felvétele az elhelyezésbe

            connect(buttonTable[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }
}


void TicTacToeWidget::buttonClicked()
{
    QPushButton* senderButton = dynamic_cast <QPushButton*> (QObject::sender());
    int location = tableLayout->indexOf(senderButton);

    stepGame(location / 3, location % 3);
}

void TicTacToeWidget::newGameButtonClicked()
{
    newGame();
}

void TicTacToeWidget::checkGame()
{
    int won = 0;

    for(int i = 0; i < 3; ++i) // ellenőrzések végrehajtása
    {
        if (gameTable[i][0] != 0 && gameTable[i][0] == gameTable[i][1] && gameTable[i][1] == gameTable[i][2])
            won = gameTable[i][0];
    }
    for(int i = 0; i < 3; ++i)
    {
        if (gameTable[0][i] != 0 && gameTable[0][i] == gameTable[1][i] && gameTable[1][i] == gameTable[2][i])
            won = gameTable[0][i];
    }
    if (gameTable[0][0] != 0 && gameTable[0][0] == gameTable[1][1] && gameTable[1][1] == gameTable[2][2])
        won = gameTable[0][0];
    if (gameTable[0][2] != 0 && gameTable[0][2] == gameTable[1][1] && gameTable[1][1] == gameTable[2][0])
        won = gameTable[0][2];

    if (won == 1) // az eredmény függvényében jelenítjük meg a győztest
    {
        QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("Az X nyerte a játékot!"));
        newGame();
    }
    else if (won == 2)
    {
        QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("A O nyerte a játékot!"));
        newGame();
    }
    else if (stepCount == 9)
    {
        QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("A játék döntetlen lett!"));
        newGame();
    }
}
