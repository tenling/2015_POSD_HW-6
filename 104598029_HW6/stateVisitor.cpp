#include "stateVisitor.h"

stateVisitor::stateVisitor(Graphics* target , Graphics* parents, int state){
    this->target = target;
    composite.push_back(parents);
    frontGraphics = parents;
    this->state = state;
    done = false;
}

void stateVisitor::visitCompositeGraphics(CompositeGraphics *cg){
    if(target->getBoundingBox().describe() == cg->getBoundingBox().describe()){
        std::cout << "find CompositeGraphics " << cg->getBoundingBox().describe() << std::endl;
        parents = (CompositeGraphics *)composite.back();
        donevector = parents->change(target,state);
        done = true;
    }
    composite.push_back(cg);
    frontGraphics = cg;
}
void stateVisitor::visitSimpleGraphics(SimpleGraphics *sg){
    if(target->getBoundingBox().describe() == sg->getBoundingBox().describe()){
        std::cout << "find SimpleGraphics " << sg->shape()->describe() << std::endl;
        parents = (CompositeGraphics *)composite.back();
        donevector = parents->change(target,state);
        done = true;
    }
    frontGraphics = sg;
}
void stateVisitor::enter(){
}
void stateVisitor::leave(){
    if(done){
        parents->setvector(donevector);
        done = false;
    }
    composite.pop_back();
}
