#include "clickableqlabel.h"
#include  <QMainWindow>
#include <QLayout>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "QCustomWidget.h"
#include "zoomqgraphicsview.h"
ClickAbleQLabel::ClickAbleQLabel(QWidget *parent)
{
    this->setParent(parent);
}

ClickAbleQLabel::~ClickAbleQLabel(){}

void ClickAbleQLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClickQlabel();
}

void ClickAbleQLabel::newImgShowWin()
{
    QCustomWidget *imgWin =  new QCustomWidget();
    imgWin->setWindowTitle(this->picName);
    ZoomQGraphicsView *ImgView = new ZoomQGraphicsView();

    QGraphicsScene *scene = new QGraphicsScene();

    QGraphicsPixmapItem *imgShowItem = new QGraphicsPixmapItem();
    imgShowItem->setPixmap(this->noScalePic);

    scene->addItem(imgShowItem);
    ImgView->setScene(scene);

    QHBoxLayout  *layout = new QHBoxLayout ;
    layout->addWidget(ImgView);
    imgWin->setLayout(layout);
    imgWin->show();
}

void ClickAbleQLabel::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees;                                     // 定义指针类型参数numDegrees用于获取滚轮转角
    numDegrees = event->angleDelta();                      // 获取滚轮转角
    int step = 0;                                          // 设置中间参数step用于将获取的数值转换成整数型
    if (!numDegrees.isNull())                              // 判断滚轮是否转动
        step = numDegrees.y();                             // 将滚轮转动数值传给中间参数step
    event->accept();

    // 获取事件
    int currentWidth = this->width();                  // 获取当前图像的宽
    int currentHeight = this->height();                // 获取当前图像的高
    currentWidth += step;                                  // 对当前图像的高累加
    currentHeight += step;

    this->pixmap() = this->pixmap().scaled(currentWidth, currentHeight,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->setPixmap(this->pixmap());
    this->update();

}

