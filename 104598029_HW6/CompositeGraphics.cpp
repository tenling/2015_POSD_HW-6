#include "CompositeGraphics.h"
#include <algorithm>
#include "Rectangle.h"
#include "GraphicsVisitor.h"
#include "AreaVisitor.h"

CompositeGraphics::CompositeGraphics(){}
void CompositeGraphics::add(Graphics *g) {g_obj.push_back(g);}
Rectangle CompositeGraphics::getBoundingBox() {
    if (g_obj.size() == 0)
        return Graphics::getBoundingBox();

    std::vector<int> minx;
    std::vector<int> miny;
    std::vector<int> maxx;
    std::vector<int> maxy;

    std::vector<Graphics *>::iterator i;
    for (i=g_obj.begin(); i!=g_obj.end();++i) {
        minx.push_back((*i)->getBoundingBox().llx());
        miny.push_back((*i)->getBoundingBox().lly());
        maxx.push_back((*i)->getBoundingBox().urx());
        maxy.push_back((*i)->getBoundingBox().ury());
    }
    int llx = *min_element(minx.begin(),minx.end());
    int lly = *min_element(miny.begin(),miny.end());
    int urx = *max_element(maxx.begin(),maxx.end());
    int ury = *max_element(maxy.begin(),maxy.end());

    return Rectangle(llx,lly,urx-llx,ury-lly);
}

void CompositeGraphics::accept(GraphicsVisitor & av) {
    av.visitCompositeGraphics(this);
    av.enter();

    for(std::vector<Graphics *>::iterator it = g_obj.begin(); it != g_obj.end() ; it++){
        (*it)->accept(av);
    }

    //for (auto e:g_obj)
        //e->accept(av);
    av.leave();
}

std::vector<Graphics *> CompositeGraphics::getVector(){
    return g_obj;
}

void CompositeGraphics::setxy(int x, int y){
}

std::vector<Graphics *> CompositeGraphics::change(Graphics* target, int state){
    std::vector<Graphics *> temp1 = g_obj;
    std::vector<Graphics *> temp2;
    Graphics* temp = temp1.back();
    temp2.push_back(temp);
    temp1.pop_back();
    //switch front
    if(state == 1){
        while(!temp1.empty()){
            if(temp->getBoundingBox().describe() == target->getBoundingBox().describe()){
                std::cout << "Target : " << target->getBoundingBox().describe() <<std::endl;
                temp2.pop_back();
                temp2.push_back(temp1.back());
                temp1.pop_back();
                temp1.push_back(temp);
                temp1.push_back(temp2.back());
                temp2.pop_back();
                break;
            }
            else{
                std::cout << "switch : " << temp1.back()->getBoundingBox().describe() << std::endl;
                temp = temp1.back();
                temp2.push_back(temp);
                temp1.pop_back();
            }
        }
        if(temp1.empty()){
            std::cout << "Error: there is the last object!" << std::endl;
        }
    }
    else{
        while(!temp2.empty()){
            if(temp->getBoundingBox().describe() == target->getBoundingBox().describe()){
                std::cout << "Target : " << target->getBoundingBox().describe() <<std::endl;
                temp2.pop_back();
                temp1.push_back(temp2.back());
                temp2.pop_back();
                temp1.push_back(temp);
                break;
            }
            else{
                std::cout << "switch : " << temp1.back()->getBoundingBox().describe() << std::endl;
                temp = temp1.back();
                temp2.push_back(temp);
                temp1.pop_back();
            }
        }
        if(temp2.empty()){
            std::cout << "Error: there is the top object!" << std::endl;
        }
    }
    while(!temp2.empty()){
        temp1.push_back(temp2.back());
        temp2.pop_back();
    }
    return temp1;
}

void CompositeGraphics::setvector(std::vector<Graphics *> g_obj){
    this->g_obj = g_obj;
}
