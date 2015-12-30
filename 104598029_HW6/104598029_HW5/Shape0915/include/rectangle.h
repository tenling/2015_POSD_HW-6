#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include <vector>
#include "Shape.h"

class rectangle : public Shape{
public:
    rectangle(int ll_x, int ll_y, int length, int high);
    int area();
private:
    int x, y;
    int l;
};


#endif // RECTANGLE_H
