#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include "field.h"
#include <QList>

class ConnectFour
{
private:
    QList<Field> fields;
    enum color lastTurn;
    const int MAX_ROW = 6;
    const int MAX_COL = 7;
    QList<Field> getFieldsInRow(int row, color c);
    QList<Field> getFieldsInCol(int col, color c);
    QList<Field> getAllSameTopLeftRightBotField(Field field);
    QList<Field> getAllSameBotLeftRightTopField(Field field);
    QList<Field> sortFieldsByRow(QList<Field> fields);
    QList<Field> sortFieldsByCol(QList<Field> fields);
    QList<Field> sortFieldTopLeftRightBotDiagonale(QList<Field> fields);
    QList<Field> sortFieldBotLeftRightTopDiagonale(QList<Field> fields);
public:
    ConnectFour();
    bool isColumnFull(int col);
    int getNextFreeRowInCol(int col);
    enum color currentTurn();
    int isGameFinished();   //-1 => not finished, 0 => undecided, 1 => blue wins & 2 => red wins
    bool putFieldInCol(int col, enum color c);
    bool isSameGame(ConnectFour game2);

};

#endif // CONNECTFOUR_H
