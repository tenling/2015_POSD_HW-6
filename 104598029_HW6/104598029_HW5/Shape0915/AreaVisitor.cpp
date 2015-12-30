#include "AreaVisitor.h"

AreaVisitor::AreaVisitor(){
    a=0;
}
void AreaVisitor::visitSimpleGraphics(SimpleGraphics *s){
      a += s->getShape()->area();
}
void AreaVisitor::visitCompositeGraphics(CompositeGraphics *c){
}
int AreaVisitor::area(){
    return a;
}
void AreaVisitor::stateclose(){
}
