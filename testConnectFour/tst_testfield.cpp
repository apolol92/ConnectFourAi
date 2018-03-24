#include <QString>
#include <QtTest>
#include "../untitled/field.h"

class testField : public QObject
{
    Q_OBJECT

public:
    testField();

private Q_SLOTS:
    void testCase1();
    void testSetRow();
    void testSetCol();
    void testSetColor();
    void testIsSameCol();
    void testIsNotSameCol();
    void testIsSameRow();
    void testIsNotSameRow();
    void testIsSameDiagonaleLeftTop2RightBot();
    void testIsNotSameDiagonaleLeftTop2RightBot();
    void testIsSameDiagonaleLeftBot2RightTop();
    void testIsNotSameDiagonaleLeftBot2RightTop();
    void testIsColliding();
    void testIsNotColliding();
    void testSameColor();
    void testNotSameColor();
};

testField::testField()
{

}

void testField::testCase1()
{
    QVERIFY2(true, "Failure");
}

void testField::testSetRow()
{
    Field mField;
    mField.setRow(1);
    QCOMPARE(1,mField.getRow());
}

void testField::testSetCol()
{
    Field mField;
    mField.setCol(1);
    QCOMPARE(1,mField.getCol());
}
void testField::testSetColor()
{
    Field mField;
    mField.setColor(color::blue);
    QCOMPARE(color::blue,mField.getColor());
}

void testField::testIsSameCol()
{
    Field f1(1,1,color::blue), f2(2,1,color::blue);
    QCOMPARE(true,f1.isSameCol(f2));
}
void testField::testIsNotSameCol()
{
    Field f1(1,1,color::blue), f2(1,2,color::blue);
    QCOMPARE(false,f1.isSameCol(f2));
}

void testField::testIsSameRow()
{
    Field f1(1,1,color::blue), f2(1,2,color::blue);
    QCOMPARE(true, f1.isSameRow(f2));
}

void testField::testIsNotSameRow()
{
    Field f1(2,1,color::blue), f2(1,2,color::blue);
    QCOMPARE(false, f1.isSameRow(f2));
}
void testField::testIsSameDiagonaleLeftTop2RightBot()
{
    Field f1(2,1,color::blue), f2(1,2,color::blue);
    QCOMPARE(true, f1.isSameDiagonaleLeftTop2RightBot(f2));
}
void testField::testIsSameDiagonaleLeftBot2RightTop()
{
    Field f1(0,1,color::blue), f2(1,2,color::blue);
    QCOMPARE(true, f1.isSameDiagonaleLeftBot2RightTop(f2));
}
void testField::testIsNotSameDiagonaleLeftBot2RightTop()
{
    Field f1(1,1,color::blue), f2(2,1,color::blue);
    QCOMPARE(false, f1.isSameDiagonaleLeftBot2RightTop(f2));
}
void testField::testIsNotSameDiagonaleLeftTop2RightBot()
{
    Field f1(1,2,color::blue), f2(1,1,color::blue);
    QCOMPARE(false, f1.isSameDiagonaleLeftTop2RightBot(f2));
}

void testField::testIsColliding()
{
    Field f1(1,1,color::blue), f2(1,1,color::blue);
    QCOMPARE(true, f1.isColliding(f2));
}

void testField::testIsNotColliding()
{
    Field f1(1,2,color::blue), f2(1,1,color::blue);
    QCOMPARE(false, f1.isColliding(f2));
}

void testField::testSameColor()
{
    Field f1(1,2,color::red), f2(3,5, color::red);
    QCOMPARE(true, f1.sameColor(f2));
}

void testField::testNotSameColor()
{
    Field f1(1,2,color::blue), f2(3,5, color::red);
    QCOMPARE(false, f1.sameColor(f2));
}

QTEST_APPLESS_MAIN(testField)

#include "tst_testfield.moc"
