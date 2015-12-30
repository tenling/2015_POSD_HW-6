#include "Circle.h"
#include <sstream>

const int PI=3;
Circle::Circle(int center_x, int center_y, int radius, int level)
    :cx(center_x),cy(center_y),r(radius){
        box=new BoundingBox(cx-r,cy-r,cx+r,cy+r,boxarea());
    std::stringstream ss;
       ss << "C(";
       ss << cx;
       ss << ",";
       ss << cy;
       ss << ",";
       ss << r;
       ss << ")";
       ss >> description;
       setLevel(level);
}

int Circle::area() {return PI*r*r;}
int Circle::boxarea(){return (2*r)*(2*r);}
