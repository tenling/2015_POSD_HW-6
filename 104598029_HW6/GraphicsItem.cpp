#include "GraphicsItem.h"

GraphicsItem :: GraphicsItem(Graphics *g,std::string description,QWidget *widget){
    this->g = g;
    this->description = description;
    this->widget = widget;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
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
    ss << description;
    ss >> temp1 >> temp2;
    if(this->isSelected()){
        painter->setPen(Qt::red);
    }
    else{
        if(temp1 == 'C' && temp2 == 'o'){
            painter->setPen(Qt::green);
        }
        else{
            painter->setPen(Qt::black);
        }
    }
    if(temp1 == 'C' && temp2 == 'o'){
        int llx,lly,l,w;
        llx = g->getBoundingBox().llx();
        lly = g->getBoundingBox().lly();
        l = g->getBoundingBox().getl();
        w = g->getBoundingBox().getw();
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(llx,lly,l,w);
    }
    else if(temp1 == 'C'){
        int cx,cy,r;
        ss >> cx >> temp2 >> cy >> temp2 >> r;
        painter->setBrush(Qt::blue);
        painter->drawEllipse(cx-r,cy-r,r*2,r*2);
    }
    else if(temp1 == 'R'){
        int llx,lly,l,w;
        ss >> llx >> temp2 >> lly >> temp2 >> l >> temp2 >> w;
        painter->setBrush(Qt::blue);
        painter->drawRect(llx,lly,l,w);
    }
    else if(temp1 == 'S'){
        int llx,lly,l;
        ss >> llx >> temp2 >> lly >> temp2 >> l;
        painter->setBrush(Qt::blue);
        painter->drawRect(llx,lly,l,l);
    }
}
Graphics* GraphicsItem::getGraphcis(){
    return g;
}

