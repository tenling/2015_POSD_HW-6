#ifndef QTVISITOR_H_INCLUDED
#define QTVISITOR_H_INCLUDED

#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "GraphicsVisitor.h"
#include "GraphicsItem.h"
#include "GraphicsGroupItem.h"
#include "GraphicsScene.h"

#include <String>
#include <QGraphicsScene>
#include <QWidget>
#include <vector>

class GraphicsGroupItem;

class QTVisitor : public GraphicsVisitor {
private:
    GraphicsScene *scene;
    QWidget *widget;
    void drawCircle(SimpleGraphics *sg);
    void drawSquare(SimpleGraphics *sg);
    void drawRectangle(SimpleGraphics *sg);
    std::vector <GraphicsItem *> graphics_temp;
    std::vector <GraphicsItem *> composite_temp;
public:
    QTVisitor(QWidget* widget, GraphicsScene* scene);
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics(CompositeGraphics *cg);
    GraphicsScene* getQGraphicsScene();
    void setScene(GraphicsScene *gs);
    void enter();
    void leave();
};


#endif // QTVISITOR_H_INCLUDED
