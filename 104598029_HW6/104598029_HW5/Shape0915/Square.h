#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "Shape.h"

class Square : public Shape{
public:
    Square(int ll_x, int ll_y, int length, int level);
    int area();
private:
    int x, y;
    int l;
};

#endif // SQUARE_H_INCLUDED
