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
    qDebug()<<"Double Click detected!";
    emit doubleClickQlabel();
}



void ClickAbleQLabel::newImgShowWin()
{
    qDebug()<<"newImgShowWin Click detected!";
    qDebug()<<"what is this :"<<this->whatsThis();
//    QCustomWidget *imgWin =  new QCustomWidget();
    ZoomQGraphicsView *ImgView = new ZoomQGraphicsView();
//    ImgView->setParent(imgWin);

    QPixmap pic;
    QGraphicsScene *scene = new QGraphicsScene();

    QGraphicsPixmapItem *imgShowItem = new QGraphicsPixmapItem();
    pic.load(this->whatsThis());
    imgShowItem->setPixmap(pic);

    scene->addItem(imgShowItem);
    ImgView->setScene(scene);
    ImgView->fitInView(imgShowItem,Qt::KeepAspectRatio);
//    QHBoxLayout  *layout = new QHBoxLayout ;
//    qDebug()<<"this size()"<<this->size();
//    layout->addWidget(ImgView);
    ImgView->show();
//    imgWin->show();
}

void ClickAbleQLabel::wheelEvent(QWheelEvent *event)
{
    qDebug()<<"wheelEvent func Debug! 1111";
    QPoint numDegrees;                                     // 定义指针类型参数numDegrees用于获取滚轮转角
    numDegrees = event->angleDelta();                      // 获取滚轮转角
    int step = 0;                                          // 设置中间参数step用于将获取的数值转换成整数型
    if (!numDegrees.isNull())                              // 判断滚轮是否转动
    {
        step = numDegrees.y();                             // 将滚轮转动数值传给中间参数step
    }
    event->accept();
    qDebug()<<"wheelEvent func Debug! 222";

    qDebug()<<"Step is "<<step;
    // 获取事件
    qDebug()<<"wheelEvent func Debug! 333";
    int currentWidth = this->width();                  // 获取当前图像的宽
    int currentHeight = this->height();                // 获取当前图像的高
    currentWidth += step;                                  // 对当前图像的高累加
    currentHeight += step;
    qDebug()<<"currentWidth is "<<currentWidth;
    qDebug()<<"currentHeight is "<<currentHeight;
    QString imgsize;// 对当前图像的宽累加
    if (step > 0)                                          // 判断图像是放大还是缩小
    {
            qDebug()<<"wheelEvent func Debug! 444";
        imgsize = QString("图像放大,尺寸为：%1 * %2")
                .arg(currentWidth).arg(currentHeight);
        qDebug() << imgsize;                               // 打印放大后的图像尺寸
    }
    else
    {
        qDebug()<<"wheelEvent func Debug! 555";
        imgsize = QString("图像缩小,尺寸为：%1 * %2")
                .arg(currentWidth).arg(currentHeight);
                                      // 打印缩小后的图像尺寸
    }
    qDebug()<<"wheelEvent func Debug! 666";
    this->pixmap() = this->pixmap().scaled(currentWidth, currentHeight,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->setPixmap(this->pixmap());
    qDebug() <<"完成缩放！" <<imgsize; // 通过更新图像显示控件的大小来更新图像大小
    qDebug()<<"wheelEvent func Debug! 777";
    this->update();

}

