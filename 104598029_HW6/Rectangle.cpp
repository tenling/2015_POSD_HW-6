#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(int ll_x, int ll_y, int length, int width)
    :x(ll_x),y(ll_y),l(length),w(width) {}
int Rectangle::area() {return l*w;}
Rectangle Rectangle::getBoundingBox() {return Rectangle(x,y,l,w);}
std::string Rectangle::describe() {
    std::ostringstream oss;
    oss << "R(" << x <<"," << y << "," << l << "," << w << ")";
    return oss.str();
}

int Rectangle::getl(){
    return l;
}

int Rectangle::getw(){
    return w;
}
void Rectangle::setx(int x){
    this->x = x;
}
void Rectangle::sety(int y){
    this->y = y;
}
