#ifndef GRAPHICSITEM_H_INCLUDED
#define GRAPHICSITEM_H_INCLUDED

#include <QPainter>
#include <string>
#include <QGraphicsItem>
#include <QWidget>
#include <string>
#include <sstream>

#include "Graphics.h"
#include "CompositeGraphics.h"
#include "SimpleGraphics.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "shape.h"

class GraphicsItem : public QGraphicsItem {
private:
    Graphics *g;
    QPainter *painter;
    QWidget *widget;
    std::string description;

public:
    GraphicsItem(Graphics *g,std::string description,QWidget* widget);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Graphics* getGraphcis();
};

#endif // GRAPHICSITEM_H_INCLUDED
