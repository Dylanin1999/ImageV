#include "zoomqgraphicsview.h"

ZoomQGraphicsView::ZoomQGraphicsView(QGraphicsView *parent)
{
    this->setParent(parent);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setAlignment(Qt::AlignCenter);

}

ZoomQGraphicsView::ZoomQGraphicsView()
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setAlignment(Qt::AlignCenter);
}


void ZoomQGraphicsView::wheelEvent(QWheelEvent *event)
{
    this->scale(1/m_scale, 1/m_scale);
    if(event->angleDelta().y() > 0){
        if(m_scale < 10){
            m_scale += 0.1;
        }else{
            m_scale = 10;
        }
    }else{
        if(m_scale > 0.1){
            m_scale -= 0.1;
        }else{
            m_scale = 0.1;
        }
    }


    this->scale(m_scale, m_scale);
    qDebug()<<"scale is:"<<m_scale;
}
