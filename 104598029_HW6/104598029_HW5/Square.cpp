#include "Square.h"
#include "Rectangle.h"
#include <sstream>
#include <string>

Square::Square(int ll_x, int ll_y, int length)
    :x(ll_x),y(ll_y),l(length) {}
int Square::area() {return l*l;}
Rectangle Square::getBoundingBox() {return Rectangle(x,y,l,l);}
std::string Square::describe() {
    std::ostringstream oss;
    oss << "S(" << x <<"," << y << "," << l <<")";
    return oss.str();
}

int Square::getx(){
    return x;
}

int Square::gety(){
    return y;
}

int Square::getl(){
    return l;
}

void Square::setx(int x){
    this->x = x;
}

void Square::sety(int y){
    this->y = y;
}
