#include "test.h"

void test::initTestCase()
{
    testmodel = new model(this);
}
void test::cleanupTestCase()
{
    delete testmodel;
}
void test::testNewGame()
{
    Cord c1 = {1,1};
    Cord c2 = {1,3};
    testmodel->newGame(c1,c2,5,"");
    QCOMPARE(c1,testmodel->currentPos(1));
    QCOMPARE(c2,testmodel->currentPos(2));

}

void test::testRobotPig()
{
    Cord c1 = {1,1};
    Cord c2 = {1,3};
    testmodel->newGame(c1,c2,5,"");

    QCOMPARE(c1,testmodel->currentPos(1));
    QCOMPARE(c2,testmodel->currentPos(2));
    QCOMPARE(c1,testmodel->player1->getCord());
    QCOMPARE(c2,testmodel->player2->getCord());
    QCOMPARE(3,testmodel->player1->getLife());
    QCOMPARE(3,testmodel->player2->getLife());

    testmodel->player1->damage();
    QCOMPARE(2,testmodel->player1->getLife());

    testmodel->player1->changeLife(1);
    QCOMPARE(1,testmodel->player1->getLife());

    QCOMPARE(Red,testmodel->player1->getPlayer());
    QCOMPARE(Blue,testmodel->player2->getPlayer());

    QCOMPARE(5,testmodel->player1->getMax());
    QCOMPARE(5,testmodel->player2->getMax());

    QCOMPARE("Up",testmodel->player1->getDirect());
    QCOMPARE("Up",testmodel->player2->getDirect());


}




//QTEST_APPLESS_MAIN(test);
//#include "test.moc"
