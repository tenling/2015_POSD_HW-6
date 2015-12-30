#include "QTVisitor.h"
#include "GraphicsItem.cpp"

using namespace std;

QTVisitor::QTVisitor(QWidget* widget,GraphicsScene* scene){
    this->widget = widget;
    this->scene = scene;
}
void QTVisitor::visitCompositeGraphics(CompositeGraphics *cs){
    GraphicsGroupItem* compositeitem = new GraphicsGroupItem(cs,widget);
    composite_temp.push_back(compositeitem);
}
void QTVisitor::visitSimpleGraphics(SimpleGraphics *sg){
    GraphicsItem* simpleitem = new GraphicsItem(sg,sg->shape()->describe(),widget);
    if(!composite_temp.empty()){
        cout << "CompositeSimple" << sg->shape()->describe() << endl;
        graphics_temp.push_back(simpleitem);
    }
    else{
        cout << "Simple" << sg->shape()->describe() << endl;
        scene->addItem(simpleitem);
    }

}

GraphicsScene* QTVisitor::getQGraphicsScene(){
    return scene;
 }

void QTVisitor::setScene(GraphicsScene *gs){
    scene = gs;
}

void QTVisitor::enter(){
    cout << "enter Composite" << endl;
}

void QTVisitor::leave(){
    while(!graphics_temp.empty()){
        cout << "Add Simple" << endl;
        composite_temp.back()->addToGroup(graphics_temp.back());
        graphics_temp.pop_back();
    }
    scene->addItem(composite_temp.back());
    GraphicsGroupItem *temp;
    temp = composite_temp.back();
    composite_temp.pop_back();
    if(!composite_temp.empty()){
        composite_temp.back()->addToGroup(temp);
    }
}
