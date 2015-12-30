#ifndef GRAPHICSSCENE_H_INCLUDED
#define GRAPHICSSCENE_H_INCLUDED

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPointF>
#include <QPoint>
#include <QGraphicsSceneMouseEvent>

class GraphicsScene : public QGraphicsScene{
private:
QPoint mousePoint;
QGraphicsView *views;
public:
GraphicsScene(QGraphicsView* view);
void mousePressEvent ( QGraphicsSceneMouseEvent * event );
void dragMoveEvent ( QGraphicsSceneMouseEvent * event );
void mouseReleaseEvent ( QGraphicsSceneMouseEvent * event );
};


#endif // GRAPHICSSCENE_H_INCLUDED
