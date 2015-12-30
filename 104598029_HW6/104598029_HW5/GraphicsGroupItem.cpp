#include "GraphicsGroupItem.h"

GraphicsGroupItem :: GraphicsGroupItem(Graphics *g,QWidget *widget){
    this->g = g;
    this->description = "Comp " + g->getBoundingBox().describe();
    this->widget = widget;
    painter = new QPainter();
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    llx = g->getBoundingBox().llx();
    lly = g->getBoundingBox().lly();
    l = g->getBoundingBox().getl();
    w = g->getBoundingBox().getw();
}

QRectF GraphicsGroupItem::boundingRect()const{
    int llx,lly,l,w;

    llx = g->getBoundingBox().llx();
    lly = g->getBoundingBox().lly();
    l = g->getBoundingBox().getl();
    w = g->getBoundingBox().getw();

    return QRectF(llx,lly,l,w);
}

void GraphicsGroupItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    std::stringstream ss;
    char temp1,temp2;
    ss << description;
    ss >> temp1 >> temp2;
     if(this->isSelected()){
        painter->setPen(Qt::red);
    }
    else{
        painter->setPen(Qt::green);
    }
    llx = g->getBoundingBox().llx();
    lly = g->getBoundingBox().lly();
    l = g->getBoundingBox().getl();
    w = g->getBoundingBox().getw();
    painter->drawRect(llx,lly,l,w);
}
Graphics* GraphicsGroupItem::getGraphcis(){
    return g;
}

void GraphicsGroupItem::update_pos(){
    QPoint point= this->pos().toPoint();
    std::cout << "Fix point : " << point.x() << "," << point.y() << std::endl;
    g->setxy(point.x(),point.y());
    std::cout << "Curr Pont : " <<  g->getBoundingBox().llx() << "," << g->getBoundingBox().lly() << std::endl;
}
