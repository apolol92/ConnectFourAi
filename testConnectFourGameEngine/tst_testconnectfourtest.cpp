#include <QString>
#include <QtTest>
#include "../untitled/field.h"
#include "../untitled/connectfour.h"

class TestConnectFourTest : public QObject
{
    Q_OBJECT

public:
    TestConnectFourTest();


private Q_SLOTS:
    void testCase1();
    void testCurrentTurnShouldBeBlue();
    void testCurrentTurnShouldBeRed();
    void testGameIsNotFinished();
    void testBlueWinsHorizontal();
    void testBlueWinsVertical();
    void testBlueWinsTopLeftRightBotDiagonale();
    void testBlueWinsBotLeftRightTopDiagonale();
    void testRedWinsHorizontal();
    void testRedWinsVertical();
    void testRedWinsTopLeftRightBotDiagonale();
    void testRedWinsBotLeftRightTopDiagonale();


};

TestConnectFourTest::TestConnectFourTest()
{
}

void TestConnectFourTest::testCase1()
{

    QVERIFY2(true, "Failure");
}

void TestConnectFourTest::testCurrentTurnShouldBeBlue()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    //cf.putFieldInCol(1,color::blue);
    QCOMPARE(color::blue,cf.currentTurn());
}

void TestConnectFourTest::testCurrentTurnShouldBeRed()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    QCOMPARE(color::red,cf.currentTurn());
}


void TestConnectFourTest::testGameIsNotFinished()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    QCOMPARE(-1, cf.isGameFinished());
}
void TestConnectFourTest::testBlueWinsHorizontal()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(3,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(4,color::blue);
    QCOMPARE(color::blue,cf.isGameFinished());
}

void TestConnectFourTest::testBlueWinsVertical()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    QCOMPARE(color::blue,cf.isGameFinished());
}
void TestConnectFourTest::testBlueWinsTopLeftRightBotDiagonale()
{
    ConnectFour cf;
    cf.putFieldInCol(4,color::blue);
    cf.putFieldInCol(3,color::red);
    cf.putFieldInCol(3,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(5,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(1,color::blue);
    QCOMPARE(color::blue,cf.isGameFinished());
}
void TestConnectFourTest::testBlueWinsBotLeftRightTopDiagonale()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(3,color::red);
    cf.putFieldInCol(3,color::blue);
    cf.putFieldInCol(0,color::red);
    cf.putFieldInCol(3,color::blue);
    cf.putFieldInCol(4,color::red);
    cf.putFieldInCol(4,color::blue);
    cf.putFieldInCol(4,color::red);
    cf.putFieldInCol(4,color::blue);
    QCOMPARE(color::blue,cf.isGameFinished());
}


void TestConnectFourTest::testRedWinsHorizontal()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(3,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(4,color::red);
    QCOMPARE(color::red,cf.isGameFinished());
}
void TestConnectFourTest::testRedWinsVertical()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(1,color::red);
    QCOMPARE(color::red,cf.isGameFinished());
}
void TestConnectFourTest::testRedWinsTopLeftRightBotDiagonale()
{
    ConnectFour cf;
    cf.putFieldInCol(4,color::red);
    cf.putFieldInCol(3,color::blue);
    cf.putFieldInCol(3,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(5,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(1,color::blue);
    cf.putFieldInCol(1,color::red);
    QCOMPARE(color::red,cf.isGameFinished());
}
void TestConnectFourTest::testRedWinsBotLeftRightTopDiagonale()
{
    ConnectFour cf;
    cf.putFieldInCol(1,color::red);
    cf.putFieldInCol(2,color::blue);
    cf.putFieldInCol(2,color::red);
    cf.putFieldInCol(3,color::blue);
    cf.putFieldInCol(3,color::red);
    cf.putFieldInCol(0,color::blue);
    cf.putFieldInCol(3,color::red);
    cf.putFieldInCol(4,color::blue);
    cf.putFieldInCol(4,color::red);
    cf.putFieldInCol(4,color::blue);
    cf.putFieldInCol(4,color::red);
    QCOMPARE(color::red,cf.isGameFinished());
}

QTEST_APPLESS_MAIN(TestConnectFourTest)

#include "tst_testconnectfourtest.moc"
