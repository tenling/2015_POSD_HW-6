#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <vector>
#include "BoundingBox.h"
#include <string>

class Shape{
public:
    shape();
    BoundingBox *box;
    virtual int area()=0;
    std::string description;
    std::string describe();
    BoundingBox getBoundingBox();
    int getLevel();
    void setLevel(int level);
private:
    int level;
};
int areaSum(std::vector<Shape *> v);
#endif // SHAPE_H_INCLUDED
