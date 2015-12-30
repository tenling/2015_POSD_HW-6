#ifndef GRAPHICSGROUPITEM_H_INCLUDED
#define GRAPHICSGROUPITEM_H_INCLUDED

#include <QGraphicsItemGroup>
#include <QPainter>
#include <QWidget>
#include <string>

#include "Graphics.h"
#include "CompositeGraphics.h"
#include "SimpleGraphics.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "GraphicsItem.h"
#include "QTVisitor.h"

class GraphicsGroupItem : public QGraphicsItemGroup{
private:
    Graphics *g;
    QPainter *painter;
    QWidget *widget;
    std::string description;
    int llx,lly,l,w;
public:
    GraphicsGroupItem(Graphics* g,QWidget* widget);
    QRectF boundingRect();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Graphics* getGraphcis();
};

#endif // GRAPHICSGROUPITEM_H_INCLUDED
