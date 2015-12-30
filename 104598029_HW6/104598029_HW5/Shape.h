#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <string>

class Rectangle;

class Shape {
public:
    virtual int area() = 0;
    virtual Rectangle getBoundingBox()=0;
    virtual std::string describe() {return std::string("");};
    virtual void setx(int x)=0;
    virtual void sety(int y)=0;
};


#endif // SHAPE_H_INCLUDED
