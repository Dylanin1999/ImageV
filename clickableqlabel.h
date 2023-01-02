#ifndef CLICKABLEQLABEL_H
#define CLICKABLEQLABEL_H
#include <QLabel>
#include <QWheelEvent>

class ClickAbleQLabel : public QLabel
{
    Q_OBJECT
public:
    ClickAbleQLabel(QWidget *parent=nullptr);
    ~ClickAbleQLabel();

    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    QPixmap noScalePic;
    QString picName;

signals:
    void doubleClickQlabel();

public slots:
    void newImgShowWin();

};

#endif // CLICKABLEQLABEL_H
