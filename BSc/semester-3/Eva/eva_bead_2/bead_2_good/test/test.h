#ifndef TEST_H
#define TEST_H
#include <QObject>
#include <QList>
#include <QtTest/QtTest>
#include "model.h"

class test : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testNewGame();
private:
    model* testmodel;
};
#endif // TEST_H
