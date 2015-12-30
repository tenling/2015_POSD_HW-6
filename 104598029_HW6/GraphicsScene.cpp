#include "GraphicsScene.h"

GraphicsScene::GraphicsScene(QGraphicsView* views){
    this->views = views;
}

void GraphicsScene::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    views->setDragMode(QGraphicsView::ScrollHandDrag);
    mousePoint = event->scenePos().toPoint();
    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::dragMoveEvent ( QGraphicsSceneMouseEvent * event )
{
    if (views->dragMode() == QGraphicsView::RubberBandDrag)
    QGraphicsScene::mouseMoveEvent(event);
}
void GraphicsScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent * event )
{
    views->setDragMode(QGraphicsView::NoDrag);
    mousePoint = event->scenePos().toPoint();
    QRect rect(mousePoint, event->scenePos().toPoint());
    QPainterPath pp;
    pp.addRect(rect);
    setSelectionArea(pp);
    std::cout << "selected item:"<< this->selectedItems().length() << std::endl;
    QGraphicsScene::mouseReleaseEvent(event);
}
