#include "test.h"
#include <QDebug>

void test::initTestCase()
{
    testmodel = new model("", this);
}
void test::cleanupTestCase()
{
    delete testmodel;
}
void test::testNewGame()
{
    testmodel->newGame(10);
    QCOMPARE(0,testmodel->getPlayer());
    for(int i = 0; i < 10*10; ++i)
    {
        QVERIFY(testmodel->getType(i) == "Neutral"||testmodel->getType(i) == "Obstacle"
                ||testmodel->getType(i) == "Resource");
    }

    QList<int> enemy = testmodel->getEnemies();

    for(int e : enemy)
    {
        QVERIFY(e <= 100 && e >= 0);
    }

}

void test::testBigGame()
{
    testmodel->newGame(1000);
    QCOMPARE(0,testmodel->getPlayer());
    for(int i = 0; i < 1000*1000; ++i)
    {
        QVERIFY(testmodel->getType(i) == "Neutral"||testmodel->getType(i) == "Obstacle"
                ||testmodel->getType(i) == "Resource");
    }

    QList<int> enemy = testmodel->getEnemies();

    for(int e : enemy)
    {
        QVERIFY(e <= 1000000 && e >= 0);
    }
}

void test::testBadSize()
{

    testmodel->newGame(-3);
    QCOMPARE(0,testmodel->getPlayer());
    for(int i = 0; i < 9; ++i)
    {
        QVERIFY(testmodel->getType(i) == "Neutral"||testmodel->getType(i) == "Obstacle"
                ||testmodel->getType(i) == "Resource");
    }

    QList<int> enemy = testmodel->getEnemies();

}


//QTEST_APPLESS_MAIN(test);
//#include "test.moc"
