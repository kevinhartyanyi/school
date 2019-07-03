#include "test.h"

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
        QVERIFY(e <= 10 && e >= 0);
    }

}


QTEST_APPLESS_MAIN(test);
//#include "test.moc"
