#include "BoundingBox.h"

BoundingBox::BoundingBox(int ll_x,int ll_y,int ur_x,int ur_y,int arean):ll_x(ll_x),ll_y(ll_y),ur_x(ur_x),ur_y(ur_y),arean(arean){}
BoundingBox::llx(){return ll_x;}
BoundingBox::lly(){return ll_y;}
BoundingBox::urx(){return ur_x;}
BoundingBox::ury(){return ur_y;}
BoundingBox::area(){return arean;}
