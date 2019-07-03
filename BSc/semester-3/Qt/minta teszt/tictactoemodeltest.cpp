#include "t.h"

// tesztkörnyezet inicializálása
void TicTacToeModelTest::initTestCase()
{
    _model = new TicTacToeModel();
}

// tesztkörnyezet megsemmisítése
void TicTacToeModelTest::cleanupTestCase()
{
    delete _model;
}

// tesztesetek
void TicTacToeModelTest::testNewGame()
{
    _model->newGame();

    // ellenőrizzük, hogy kezdetben minden mező üres, és 0 a lépésszám
    QCOMPARE(_model->stepNumber(), 0);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            QCOMPARE(_model->getField(i, j), TicTacToeModel::NoPlayer);

}

void TicTacToeModelTest::testStepGame()
{
    _model->newGame();
    _model->stepGame(0, 0);

    // ellenőrizzük, hogy a lépésszám 1, és az X lépett először
    QCOMPARE(_model->stepNumber(), 1);
    QCOMPARE(_model->getField(0, 0), TicTacToeModel::PlayerX);

    // ellenőrizzük, hogy közben más mező nem változott
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            QVERIFY((i == 0 && j == 0) || (_model->getField(i, j) == TicTacToeModel::NoPlayer));

    // ellenőrizzük, hogy ezután a O következik
    _model->stepGame(0, 1);
    QCOMPARE(_model->stepNumber(), 2);
    QCOMPARE(_model->getField(0, 1), TicTacToeModel::PlayerO);

    // majd ismét az X
    _model->stepGame(0, 2);
    QCOMPARE(_model->stepNumber(), 3);
    QCOMPARE(_model->getField(0, 2), TicTacToeModel::PlayerX);
}

void TicTacToeModelTest::testStepGameErrors()
{
    _model->newGame();

    // ellenőrizzük, hogy nem tudunk rossz mezőre lépni
    _model->stepGame(-1, 0);
    _model->stepGame(0, -1);
    _model->stepGame(3, 0);
    _model->stepGame(0, 3);

    QCOMPARE(_model->stepNumber(), 0);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            QVERIFY(_model->getField(i, j) == TicTacToeModel::NoPlayer);

    // ellenőrizzük, hogy kétszer nem tudunk lépni ugyanarra a mezőre
    _model->stepGame(0, 0);
    _model->stepGame(0, 0);
    QCOMPARE(_model->stepNumber(), 1);
    QCOMPARE(_model->getField(0, 0), TicTacToeModel::PlayerO);
}

QTEST_APPLESS_MAIN(TicTacToeModelTest)

//#include "tictactoemodeltest.moc"
