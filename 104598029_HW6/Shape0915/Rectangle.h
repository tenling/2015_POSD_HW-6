#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "Shape.h"

class Rectangle : public Shape{
public:
    Rectangle(int ll_x, int ll_y, int length, int height , int level);
    Rectangle();
    int area();
private:
    int x, y;
    int l, h;
};


#endif // RECTANGLE_H_INCLUDED
