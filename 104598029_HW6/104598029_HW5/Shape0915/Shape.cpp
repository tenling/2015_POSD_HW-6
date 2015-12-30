#include "Shape.h"

int areaSum(std::vector<Shape *> v) {
    int sum = 0;
    std::vector<Shape *>::iterator i;
    for (i=v.begin(); i != v.end(); ++i)
        sum += (*i)->area();
    return sum;
}
BoundingBox Shape::getBoundingBox(){
    return *box;
}
std::string Shape::describe(){
    return description;
}
int Shape::getLevel(){
    return level;
}
void Shape::setLevel(int level){
    this->level=level;
}

