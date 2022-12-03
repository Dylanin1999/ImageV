#ifndef QCUSTOMWIDGET_H
#define QCUSTOMWIDGET_H

#include <QWidget>
#include "clickableqlabel.h"
class QCustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QCustomWidget(QWidget *parent = nullptr);
//    void wheelEvent(QWheelEvent *event);
signals:

};

#endif // QCUSTOMWIDGET_H
