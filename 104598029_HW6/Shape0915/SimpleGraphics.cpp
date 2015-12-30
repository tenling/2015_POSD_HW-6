#include "SimpleGraphics.h"
#include "GraphicsVisitor.h"

SimpleGraphics::SimpleGraphics(Shape *p):p(p){
    level = p -> getLevel();
}
BoundingBox SimpleGraphics::getBoundingBox(){
    return p->getBoundingBox();
}
void SimpleGraphics::add(Graphics *g){
    throw std::string("Cannot add child") ;
}
void SimpleGraphics::accept(GraphicsVisitor &g){
    g.visitSimpleGraphics(this);
}
Shape* SimpleGraphics::getShape(){
    return p;
}
