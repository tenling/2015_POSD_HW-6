#include "CompositeGraphics.h"
#include <algorithm>
#include "GraphicsVisitor.h"
#include <sstream>
#include <iostream>

CompositeGraphics::CompositeGraphics(){
    box=new BoundingBox(0,0,0,0,0);
    G_description="Comp R(0,0,0,0)";
    level= 0;
}
CompositeGraphics::CompositeGraphics(int level){
    box=new BoundingBox(0,0,0,0,0);
    G_description="Comp R(0,0,0,0)";
    this->level= level;
}
void CompositeGraphics::add(Graphics *g){
    int llx,lly,urx,ury;
    llx = box->llx();
    lly = box->lly();
    urx = box->urx();
    ury = box->ury();
    if(llx > g->getBoundingBox().llx())
    {
        llx = g->getBoundingBox().llx();
    }
    if(lly > g->getBoundingBox().lly())
    {
        lly = g->getBoundingBox().lly();
    }
    if(urx < g->getBoundingBox().urx())
    {
        urx = g->getBoundingBox().urx();
    }
    if(ury < g->getBoundingBox().ury())
    {
        ury = g->getBoundingBox().ury();
    }
    box=new BoundingBox(llx,lly,urx,ury,(urx-llx)*(ury-lly));
    G_description="Comp R(";
    std::stringstream ss;
    ss << llx;
    ss << ",";
    ss << lly;
    ss << ",";
    ss << urx-llx;
    ss << ",";
    ss << ury-lly;
    ss << ")";
    G_description+=ss.str();
    gv.push_back(g);

}

void CompositeGraphics::accept(GraphicsVisitor &g) {
      g.visitCompositeGraphics(this);
      for (auto e: gv){
        e->accept(g);
      }
      g.stateclose();
}
