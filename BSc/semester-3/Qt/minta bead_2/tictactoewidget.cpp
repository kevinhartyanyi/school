#include "tictactoewidget.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>

TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(400, 400);
    setBaseSize(400,400);
    setWindowTitle(tr("Tic-Tac-Toe"));

    // mezők grafikája:
    _tableGraphics.append(QLineF(0, 66, 200, 66));
    _tableGraphics.append(QLineF(0, 132, 200, 132));
    _tableGraphics.append(QLineF(66, 0, 66, 200));
    _tableGraphics.append(QLineF(132, 0, 132, 200));

    // játékosok grafikája:
    _playerXGraphics.append(QLineF(10, 10, 56, 56));
    _playerXGraphics.append(QLineF(10, 56, 56, 10));
    _playerOGraphics = QRectF(10.0, 10.0, 46.0, 46.0);

    // modell eseményeinek feldolgozása
    connect(&_model, SIGNAL(gameWon(TicTacToeModel::Player)), this, SLOT(model_gameWon(TicTacToeModel::Player)));
    connect(&_model, SIGNAL(gameOver()), this, SLOT(model_gameOver()));
    connect(&_model, SIGNAL(fieldChanged(int, int, TicTacToeModel::Player)), this, SLOT(model_fieldChanged(int, int, TicTacToeModel::Player)));

    _model.newGame(); // új játék indítása
}

void TicTacToeWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this); // rajzoló objektum
    painter.setRenderHint(QPainter::Antialiasing); // élsimítás használata
    painter.scale(width() / 200.0, height() / 200.0); // skálázás

    painter.setPen(QPen(Qt::black, 2)); // toll beállítása
    painter.setBrush(Qt::red); // ecset beállítása
    painter.drawLines(_tableGraphics); // tábla kirajzolása

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            painter.save(); // elmentjük a rajztulajdonságokat
            painter.translate(i * 200.0 / 3 , j * 200.0 / 3); // elmozdítjuk a rajzpontot a megfelelő mezőre

            // mező kirajzolása a játékos függvényében
            switch (_model.getField(i, j))
            {
            case TicTacToeModel::PlayerX:
                painter.setPen(QPen(Qt::blue, 4)); // toll beállítása
                painter.drawLines(_playerXGraphics); // megfelelõ grafika kirajzolása
                break;
            case TicTacToeModel::PlayerO:
                painter.setPen(QPen(Qt::black, 2)); // toll beállítása
                painter.drawEllipse(_playerOGraphics);
                break;
            }
            painter.restore(); // visszatöltjük a korábbi állapotot
        }
    }
}

void TicTacToeWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_N && QApplication::keyboardModifiers() == Qt::ControlModifier)
    {
        // lekezeljük a Ctrl+N kombinációt
        _model.newGame();
        update();
    }
}

void TicTacToeWidget::mousePressEvent(QMouseEvent *event)
{
    // az event->pos() megadja az egérpozíciót, ami QPoint típusú, ebbõl kiszámolható, melyik mezőn vagyunk:
    int x = event->pos().x() * 3 / width();
    int y = event->pos().y() * 3 / height();

    _model.stepGame(x, y); // játék léptetése
}

void TicTacToeWidget::model_gameWon(TicTacToeModel::Player player)
{
    // az eredmény függvényében jelenítjük meg a győztest
    switch (player)
    {
    case TicTacToeModel::PlayerX:
        QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("Az X nyerte a játékot!"));
        _model.newGame();
        break;
    case TicTacToeModel::PlayerO:
        QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("A O nyerte a játékot!"));
        _model.newGame();
        break;
    }
}

void TicTacToeWidget::model_gameOver()
{
    QMessageBox::information(this, trUtf8("Játék vége!"), trUtf8("A játék döntetlen lett!"));
    _model.newGame();
}

void TicTacToeWidget::model_fieldChanged(int x, int y, TicTacToeModel::Player player)
{
    update();
}
