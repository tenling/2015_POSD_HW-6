#ifndef COMPOSITEGRAPHICS_H_INCLUDED
#define COMPOSITEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include <vector>
#include <list>
#include <iostream>
#include "GraphicsVisitor.h"

class CompositeGraphics : public Graphics {
public:
    CompositeGraphics();
    void add (Graphics *g);
    Rectangle getBoundingBox();
    void accept(GraphicsVisitor & av);
    void setxy(int x,int y);
    std::vector<Graphics *> getVector();
    std::vector<Graphics *> change(Graphics* target , int state);
    void setvector(std::vector<Graphics *> g_obj);
private:
    std::vector<Graphics *> g_obj;
};

#endif // COMPOSITEGRAPHICS_H_INCLUDED
