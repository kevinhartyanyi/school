#ifndef T_H
#define T_H
#include <QString>
#include <QtTest>
#include "tictactoemodel.h"

class TicTacToeModelTest : public QObject // tesutkörnyezet
{
    Q_OBJECT
private:
    TicTacToeModel* _model;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testNewGame();
    void testStepGame();
    void testStepGameErrors();
};
#endif // T_H
