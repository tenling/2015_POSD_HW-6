#ifndef GRAPHICSVISITOR_H_INCLUDED
#define GRAPHICSVISITOR_H_INCLUDED
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"

class GraphicsVisitor{
public:
    virtual void visitSimpleGraphics(SimpleGraphics *s)=0;
    virtual void visitCompositeGraphics(CompositeGraphics *c)=0;
    virtual void stateclose()=0;
    int state;
};

#endif // GRAPHICSVISITOR_H_INCLUDED
