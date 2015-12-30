#include "Square.h"
#include <sstream>

Square::Square(int ll_x, int ll_y, int length, int level)
    :x(ll_x),y(ll_y),l(length){
       box = new BoundingBox(ll_x,ll_y,ll_x+l,ll_y+l,area());
       std::stringstream ss;
       ss << "S(";
       ss << x;
       ss << ",";
       ss << y;
       ss << ",";
       ss << l;
       ss << ")";
       ss >> description;
       setLevel(level);
    }
int Square::area() {return l*l;}
