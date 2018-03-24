#ifndef FIELD_H
#define FIELD_H


enum color {blue, red};

class Field
{
private:
    int row;
    int col;
    enum color c;
public:
    Field();
    Field(int row, int col, enum color c);
    int getRow();
    int getCol();
    enum color getColor();
    void setRow(int row);
    void setCol(int col);
    void setColor(enum color c);
    bool isSameCol(Field f);
    bool isSameRow(Field f);
    bool isSameDiagonaleLeftTop2RightBot(Field f);
    bool isSameDiagonaleLeftBot2RightTop(Field f);
    bool isColliding(Field f);

};

#endif // FIELD_H
