#include "GraphicsItem.h"

GraphicsItem :: GraphicsItem(SimpleGraphics *g,std::string description,QWidget *widget){
    this->g = g;
    this->description = description;
    this->widget = widget;
    painter = new QPainter();
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

QRectF GraphicsItem::boundingRect()const{
    int llx,lly,l,w;

    llx = g->getBoundingBox().llx();
    lly = g->getBoundingBox().lly();
    l = g->getBoundingBox().getl();
    w = g->getBoundingBox().getw();

    return QRectF(llx,lly,l,w);
}

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    std::stringstream ss;
    char temp1,temp2;
    description = g->shape()->describe();
    ss << description;
    ss >> temp1 >> temp2;
    if(this->isSelected()){
        painter->setPen(Qt::magenta);
    }
    else{
        painter->setPen(Qt::blue);
    }
    if(temp1 == 'C'){
        int cx,cy,r;
        ss >> cx >> temp2 >> cy >> temp2 >> r;
        painter->drawEllipse(cx-r,cy-r,r,r);
    }
    else if(temp1 == 'R'){
        int llx,lly,l,w;
        ss >> llx >> temp2 >> lly >> temp2 >> l >> temp2 >> w;
        painter->drawRect(llx,lly,l,w);
    }
    else if(temp1 == 'S'){
        int llx,lly,l;
        ss >> llx >> temp2 >> lly >> temp2 >> l;
        painter->drawRect(llx,lly,l,l);
    }
}
Graphics* GraphicsItem::getGraphcis(){
    return g;
}

void GraphicsItem::update_pos(){
    QPoint point= this->pos().toPoint();
    std::cout << "Fix point : " << point.x() << "," << point.y() << std::endl;
    g->shape()->setx(point.x());
    g->shape()->sety(point.y());
    std::cout << "Curr Pont : " <<  g->getBoundingBox().llx() << "," << g->getBoundingBox().lly() <<std::endl;
}
