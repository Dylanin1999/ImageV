#ifndef ZOOMQGRAPHICSVIEW_H
#define ZOOMQGRAPHICSVIEW_H
#include <QWheelEvent>
#include <QGraphicsView>

class ZoomQGraphicsView : public QGraphicsView
{
public:
    ZoomQGraphicsView(QGraphicsView *parent);
    ZoomQGraphicsView();
    void wheelEvent(QWheelEvent *event);
    float m_scale = 1;
};

#endif // ZOOMQGRAPHICSVIEW_H
