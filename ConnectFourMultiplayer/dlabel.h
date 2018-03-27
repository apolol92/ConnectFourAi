#ifndef DLABEL_H
#define DLABEL_H

#include<QLabel>

class DLabel : public QLabel
{
public:
    DLabel();
    DLabel(int r, int c);
    int row, col;
};

#endif // DLABEL_H
