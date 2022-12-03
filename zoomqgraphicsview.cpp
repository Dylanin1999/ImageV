#include "zoomqgraphicsview.h"

ZoomQGraphicsView::ZoomQGraphicsView(QGraphicsView *parent)
{
    this->setParent(parent);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setAlignment(Qt::AlignLeft | Qt::AlignTop);

}

ZoomQGraphicsView::ZoomQGraphicsView()
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setAlignment(Qt::AlignLeft | Qt::AlignTop);
}


void ZoomQGraphicsView::wheelEvent(QWheelEvent *event)
{
//    QPointF cursorPoint = event->position();
//    QPointF scenePos = this->mapToScene(QPoint(cursorPoint.x(),cursorPoint.y()));

//    qreal viewWidth = this->viewport()->width();
//    qreal viewHeight = this->viewport()->height();

//    qreal hScale = cursorPoint.x();
//    qreal vScale = cursorPoint.y();

//    qreal scaleFactor = this->matrix().m11();
    this->scale(1/m_scale, 1/m_scale);
    if(event->angleDelta().y() > 0){
        if(m_scale < 10){
            m_scale += 0.2;
        }else{
            m_scale = 10;
        }
    }else{
        if(m_scale > 0.2){
            m_scale -= 0.2;
        }else{
            m_scale = 0.2;
        }
    }


    this->scale(m_scale, m_scale);
    qDebug()<<"scale is:"<<m_scale;
}
