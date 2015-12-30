#ifndef AREAVISITOR_H_INCLUDED
#define AREAVISITOR_H_INCLUDED

#include "GraphicsVisitor.h"

class AreaVisitor : public GraphicsVisitor{
public:
    AreaVisitor();
    void visitSimpleGraphics(SimpleGraphics *s);
    void visitCompositeGraphics(CompositeGraphics *c);
    int area();
    void stateclose();
private:
    int a;
};

#endif // AREAVISITOR_H_INCLUDED
