#include "Rectangle.h"
#include "BoundingBox.cpp"
#include <sstream>

Rectangle::Rectangle(int ll_x, int ll_y, int length, int height, int level):
    x(ll_x),y(ll_y),l(length),h(height) {
       box = new BoundingBox(x,y,x+l,y+h,area());
       std::stringstream ss;
       ss << "R(";
       ss << x;
       ss << ",";
       ss << y;
       ss << ",";
       ss << l;
       ss << ",";
       ss << h;
       ss << ")";
       ss >> description;
       setLevel(level);
    }
Rectangle::Rectangle():x(0),y(0),l(0),h(0){
    box = new BoundingBox(x,y,x+l,y+h,area());
}
int Rectangle::area() {return l*h;}

