#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(int center_x, int center_y, int radius);
    int area();
    Rectangle getBoundingBox();
    std::string describe();
    //int perimeter();
    int getcx();
    int getcy();
    int getr();
    void setx(int x);
    void sety(int y);
private:
    int cx, cy;
    int r;
};

#endif // CIRCLE_H_INCLUDED
