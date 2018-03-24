#include "connectfour.h"

ConnectFour::ConnectFour()
{
    this->lastTurn = color::red;
}
bool ConnectFour::isColumnFull(int col)
{
    int counter = 0;
    foreach (Field f, this->fields)
    {
        if(f.getCol()==col)
        {
            counter++;
            if(counter==this->MAX_ROW)
            {
                return true;
            }
        }
    }
    return false;
}

enum color ConnectFour::currentTurn()
{
    int counter = 0;
    foreach (Field f, this->fields)
    {
        if(f.getColor()==color::blue)
        {
            counter++;

        }
        else if(f.getColor()==color::red)
        {
            counter--;
        }
    }
    if(counter>0)
    {
        this->lastTurn = color::blue;
        return color::red;
    }
    else if(counter < 0)
    {
        this->lastTurn = color::red;
        return color::blue;
    }
    else {
        if(this->lastTurn == color::red)
        {
            this->lastTurn = color::blue;
            return color::blue;
        }
        else
        {
            this->lastTurn = color::red;
            return color::red;
        }
    }
}

int ConnectFour::getNextFreeRowInCol(int col)
{
    int counter = 0;
    foreach (Field f, this->fields)
    {
        if(f.getCol()==col)
        {
            counter++;

        }
    }
    return counter;
}


int ConnectFour::isGameFinished()
{
    if(this->fields.length()<7)
    {
        return -1;
    }
    //Check for row-winnings
    for(int i = 0; i < this->fields.length(); i++)
    {
        QList<Field> currentRowFields = this->getFieldsInRow(this->fields[i]);
        int counter = 0;
        for(int d = 0; d < currentRowFields.length(); d++)
        {
            for(int z = d+1; z < currentRowFields.length();z++)
            {
                if(currentRowFields[d].getColDistance(currentRowFields[z])==1+counter)
                {
                    counter++;
                    if(counter==4)
                    {
                        return true;
                    }
                }
                else{
                    counter=0;
                    break;
                }
            }
        }
    }
    //Check for col-winnings
    for(int i = 0; i < this->fields.length(); i++)
    {
        int counter = 0;
        QList<Field> currentColFields = this->getFieldsInCol(fields[i]);
        for(int d = 0; d < currentColFields.length(); d++)
        {
            for(int z = d+1; z < currentColFields.length();z++)
            {
                if(currentColFields[d].getRowDistance(currentColFields[z])==counter+1)
                {
                    counter++;
                    if(counter==4)
                    {
                        return true;
                    }

                }
                else
                {
                    counter = 0;
                    break;
                }
            }
        }
    }
    //Check for TopLeftDiagonales-winnings
    for(int i = 0; i < this->fields.length(); i++)
    {
        QList<Field> currentDiagonaleFields = getAllSameTopLeftRightBotField(fields[i]);
        currentDiagonaleFields = sortFieldTopLeftRightBotDiagonale(currentDiagonaleFields);
        int counter = 0;
        for(int d = 0; d < currentDiagonaleFields.length(); d++)
        {
            for(int z = d+1; z < currentDiagonaleFields.length();z++)
            {
                if(currentDiagonaleFields[d].getColDistance(currentDiagonaleFields[z])==1+counter)
                {
                    counter++;
                    if(counter==4)
                    {
                        return true;
                    }
                }
                else{
                    counter=0;
                    break;
                }
            }
        }
    }
    //Check for BotLeftDiagonales-winnings
    for(int i = 0; i < this->fields.length(); i++)
    {
        QList<Field> currentDiagonaleFields = getAllSameBotLeftRightTopField(fields[i]);
        currentDiagonaleFields = sortFieldBotLeftRightTopDiagonale(currentDiagonaleFields);
        int counter = 0;
        for(int d = 0; d < currentDiagonaleFields.length(); d++)
        {
            for(int z = d+1; z < currentDiagonaleFields.length();z++)
            {
                if(currentDiagonaleFields[d].getColDistance(currentDiagonaleFields[z])==1+counter)
                {
                    counter++;
                    if(counter==4)
                    {
                        return true;
                    }
                }
                else{
                    counter=0;
                    break;
                }
            }
        }
    }
    return false;
}

QList<Field> ConnectFour::getAllSameBotLeftRightTopField(Field field)
{
    QList<Field> dFields;
    dFields.append(field);
    for(int i = 0; i < this->fields.length();i++)
    {
        if(fields[i].isColliding(field)==false)
        {
            if(fields[i].sameColor(field)&&fields[i].isSameDiagonaleLeftBot2RightTop(field))
            {
                dFields.append(fields[i]);

            }
        }
    }
    return dFields;
}

QList<Field> ConnectFour::sortFieldBotLeftRightTopDiagonale(QList<Field> fields)
{
    return sortFieldsByRow(fields);
}

QList<Field> ConnectFour::getAllSameTopLeftRightBotField(Field field)
{
    QList<Field> dFields;
    dFields.append(field);
    for(int i = 0; i < this->fields.length();i++)
    {
        if(fields[i].isColliding(field)==false)
        {
            if(fields[i].sameColor(field)&&fields[i].isSameDiagonaleLeftTop2RightBot(field))
            {
                dFields.append(fields[i]);

            }
        }
    }
    return dFields;
}

QList<Field> ConnectFour::sortFieldTopLeftRightBotDiagonale(QList<Field> fields)
{
    fields = sortFieldsByRow(fields);
    QList<Field> nFields;
    for(int i = fields.length()-1; i>=0;i--)
    {
        nFields.append(fields[i]);
    }
    return nFields;
}

QList<Field> ConnectFour::sortFieldsByRow(QList<Field> fields)
{
    for(int i = 1; i < fields.length(); i++)
    {
        int j = i;
        while(j>0 && fields[j-1].getRow()>fields[j].getRow())
        {
            Field tmp(fields[j]);
            fields[j] = Field(fields[j-1]);
            fields[j-1] = Field(tmp);
            j = j - 1;
        }
    }
    return fields;
}

QList<Field> ConnectFour::sortFieldsByCol(QList<Field> fields)
{
    for(int i = 1; i < fields.length(); i++)
    {
        int j = i;
        while(j>0 && fields[j-1].getCol()>fields[j].getCol())
        {
            Field tmp(fields[j]);
            fields[j] = Field(fields[j-1]);
            fields[j-1] = Field(tmp);
            j = j - 1;
        }
    }
    return fields;
}

QList<Field> ConnectFour::getFieldsInRow(Field field)
{
    QList<Field> rFields;
    rFields.append(field);
    for(int i = 0; i < this->fields.length();i++)
    {
        if(fields[i].isColliding(field)==false)
        {
            if(fields[i].sameColor(field)&&fields[i].isSameRow(field))
            {
                rFields.append(fields[i]);

            }
        }
    }
    return sortFieldsByCol(rFields);
}

QList<Field> ConnectFour::getFieldsInCol(Field field)
{
    QList<Field> cFields;
    cFields.append(field);
    for(int i = 0; i < this->fields.length();i++)
    {
        if(fields[i].isColliding(field)==false)
        {
            if(fields[i].sameColor(field)&&fields[i].isSameCol(field))
            {
                cFields.append(fields[i]);

            }
        }
    }
    return sortFieldsByRow(cFields);
}

bool ConnectFour::putFieldInCol(int col, enum color c)
{
    if(this->isColumnFull(col)==false){
        int nextFreeRow = this->getNextFreeRowInCol(col);
        this->fields.append(Field(nextFreeRow,col,c));
        return true;
    }
    return false;
}
bool ConnectFour::isSameGame(ConnectFour game2)
{
    if(this->currentTurn()==game2.currentTurn())
    {
        foreach (Field f, this->fields)
        {
            bool check = false;
            foreach (Field f2, game2.fields)
            {
                if(f.isColliding(f2) && f.sameColor(f2))
                {
                    check = true;
                }
            }
            if(check==false)
            {
                return false;
            }

        }
        return true;
    }
    return false;
}

