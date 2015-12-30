#include "Circle.h"
#include "Rectangle.h"
#include <sstream>

const int PI=3;

Circle::Circle(int center_x, int center_y, int radius)
    :cx(center_x),cy(center_y),r(radius) {}
int Circle::area() {return PI*r*r;}
Rectangle Circle::getBoundingBox() {return Rectangle(cx-r,cy-r,r*2,r*2);}
std::string Circle::describe() {
    std::ostringstream oss;
    oss << "C(" << cx <<"," << cy << "," << r <<")";
    return oss.str();
}

int Circle::getcx(){
    return cx;
}
int Circle::getcy(){
    return cy;
}
int Circle::getr(){
    return r;
}
void Circle::setx(int x){
    cx = x;
}
void Circle::sety(int y){
    cy = y;
}
