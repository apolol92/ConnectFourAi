#include "field.h"

Field::Field()
{
    this->row = -1;
    this->col = -1;
    this->c = color::blue;
}

Field::Field(const Field &f)
{
    this->row = f.row;
    this->col = f.col;
    this->c = f.c;
}

Field::Field(int row, int col, enum color c)
{
    this->row = row;
    this->col = col;
    this->c = c;
}

int Field::getRow()
{
    return this->row;
}
int Field::getCol()
{
    return this->col;
}
enum color Field::getColor()
{
    return this->c;
}
void Field::setRow(int row)
{
    this->row = row;
}
void Field::setCol(int col)
{
    this->col = col;
}
void Field::setColor(enum color c)
{
    this->c = c;
}
bool Field::isSameCol(Field f)
{
    return this->col == f.col;
}
bool Field::isSameRow(Field f)
{
    return this->row == f.row;
}
bool Field::isSameDiagonaleLeftTop2RightBot(Field f)
{
    return (this->row+this->col) == (f.row + f.col);
}
bool Field::isSameDiagonaleLeftBot2RightTop(Field f)
{
    return (this->row-this->col) == (f.row - f.col);
}

bool Field::isColliding(Field f) {
    return (this->row == f.row) && (this->col == f.col);
}

bool Field::sameColor(Field f)
{
    return this->getColor() == f.getColor();
}

int Field::getColDistance(Field f)
{
    return f.col-this->col;
}

int Field::getRowDistance(Field f)
{
    return f.row - this->row;
}

int Field::getGridRow()
{
    return (5-this->row);
}
int Field::getGridCol()
{
    return this->col;
}
