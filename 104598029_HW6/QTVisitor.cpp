#include "QTVisitor.h"
#include "GraphicsItem.cpp"

using namespace std;

QTVisitor::QTVisitor(QWidget* widget,GraphicsScene* scene){
    this->widget = widget;
    this->scene = scene;
}
void QTVisitor::visitCompositeGraphics(CompositeGraphics *cs){
    GraphicsItem* compositeitem = new GraphicsItem(cs,"Comp ",widget);
    scene->addItem(compositeitem);
}
void QTVisitor::visitSimpleGraphics(SimpleGraphics *sg){
    GraphicsItem* simpleitem = new GraphicsItem(sg,sg->shape()->describe(),widget);
    scene->addItem(simpleitem);
}

GraphicsScene* QTVisitor::getQGraphicsScene(){
    return scene;
 }

void QTVisitor::setScene(GraphicsScene *gs){
    scene = gs;
}

void QTVisitor::enter(){
}

void QTVisitor::leave(){
}
