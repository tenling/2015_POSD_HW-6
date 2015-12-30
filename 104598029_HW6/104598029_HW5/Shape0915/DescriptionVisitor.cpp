#include "DescriptionVisitor.h"
#include <iostream>
DescriptionVisitor::DescriptionVisitor(){
    state=0;
}
void DescriptionVisitor::visitSimpleGraphics(SimpleGraphics *s){
    if(state != 0){
        for (int i=0; i < state ; i++)
        {
            d+="  ";
        }
    }
    d += s->getShape()->describe();
    d += "\n";
    //std::cout<< d << std::endl;

}
void DescriptionVisitor::visitCompositeGraphics(CompositeGraphics *c){
     if(state != 0){
        for (int i=0; i < state ; i++)
        {
            d+="  ";
        }
    }
    d+= c->describe();
    d+= "\n";
    state++;
    //std::cout<< d << std::endl;
}
std::string DescriptionVisitor::getDescription(){
    return d;
}
void DescriptionVisitor::stateclose(){
    state--;
}
