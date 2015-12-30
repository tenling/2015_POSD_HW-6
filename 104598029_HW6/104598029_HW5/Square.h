#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "Shape.h"

class Square : public Shape {
public:
    Square(int ll_x, int ll_y, int length);
    int area();
    Rectangle getBoundingBox();
    std::string describe();
    int getx();
    int gety();
    int getl();
    void setx(int x);
    void sety(int y);
private:
    int x, y;
    int l;

};


#endif // SQUARE_H_INCLUDED
