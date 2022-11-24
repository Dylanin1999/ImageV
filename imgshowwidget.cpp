#include "imgshowwidget.h"


ImgShowWidget::ImgShowWidget(QWidget *parent)
    : QWidget{parent}
{
    ImgShowLabel = new QLabel(this);
    QHBoxLayout *layout  = new QHBoxLayout();
    setLayout(layout);
    this->layout()->addWidget(ImgShowLabel);
}



