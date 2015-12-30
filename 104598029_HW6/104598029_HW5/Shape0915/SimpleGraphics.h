#ifndef SIMPLEGRAPHICS_H_INCLUDED
#define SIMPLEGRAPHICS_H_INCLUDED
#include "Graphics.h"
#include "Shape.h"
#include <vector>
#include <string>

class BoundingBox;
class GraphicsVisitor;
class SimpleGraphics : public Graphics{
public:
   SimpleGraphics(Shape *p);
   BoundingBox getBoundingBox();
   void add(Graphics *g);
   void accept(GraphicsVisitor &g);
   Shape* getShape();
private:
    Shape *p;
};

#endif // SIMPLEGRAPHICS_H_INCLUDED
