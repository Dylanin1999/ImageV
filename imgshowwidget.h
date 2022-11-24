#ifndef IMGSHOWWIDGET_H
#define IMGSHOWWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPaintEvent>
#include <QSizePolicy>

class ImgShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImgShowWidget(QWidget *parent = nullptr);
    QLabel *ImgShowLabel;
signals:

};

#endif // IMGSHOWWIDGET_H
