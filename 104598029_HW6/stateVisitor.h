#ifndef STATEVISITOR_H_INCLUDED
#define STATEVISITOR_H_INCLUDED

#include <vector>

#include "GraphicsVisitor.h"
#include "Graphics.h"
#include "CompositeGraphics.h"
#include "SimpleGraphics.h"

class stateVisitor : public GraphicsVisitor{
private:
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics(CompositeGraphics *cg);
    void enter();
    void leave();
    Graphics* frontGraphics;
    std::vector <Graphics *> composite;
    Graphics* target;
    std::vector <Graphics *> donevector;
    CompositeGraphics* parents;
    bool done;
    int state;
public:
    stateVisitor(Graphics* target,Graphics* parents, int state);
};


#endif // STATEVISITOR_H_INCLUDED
