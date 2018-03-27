#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include "field.h"
#include <QList>


class ConnectFour
{
private:

    enum color lastTurn;


public:
    QList<Field> fields;
    const int MAX_ROW = 6;
    const int MAX_COL = 7;
    ConnectFour();
    QList<Field> getFieldsInRow(Field field);
    QList<Field> getFieldsInCol(Field field);
    QList<Field> getAllSameTopLeftRightBotField(Field field);
    QList<Field> getAllSameBotLeftRightTopField(Field field);
    QList<Field> sortFieldsByRow(QList<Field> fields);
    QList<Field> sortFieldsByCol(QList<Field> fields);
    QList<Field> sortFieldTopLeftRightBotDiagonale(QList<Field> fields);
    QList<Field> sortFieldBotLeftRightTopDiagonale(QList<Field> fields);
    bool isColumnFull(int col);
    int getNextFreeRowInCol(int col);
    enum color currentTurn();
    int isGameFinished();   //-1 => not finished, 0 => undecided, 1 => blue wins & 2 => red wins
    bool putFieldInCol(int col, enum color c);
    bool isSameGame(ConnectFour game2);
    void reset();


};

#endif // CONNECTFOUR_H
