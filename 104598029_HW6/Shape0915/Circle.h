#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Shape.h"

class Circle : public Shape{
public:
    Circle(int center_x, int center_y, int radius, int level);
    int area();
    int boxarea();
private:
    int cx, cy;
    int r;
};
#endif // CIRCLE_H_INCLUDED
