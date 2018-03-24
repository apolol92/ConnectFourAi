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

QTEST_APPLESS_MAIN(testField)

#include "tst_testfield.moc"
