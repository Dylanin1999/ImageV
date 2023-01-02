#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <namechange.h>
#include <imageformatconvert.h>
#include <QButtonGroup>
#include <QGraphicsScene>
#include <QListWidgetItem>
#include <QLabel>
#include "clickableqlabel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<ClickAbleQLabel*> imgVec;
protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

private slots:
//    void OnListWidgetDoubleClicked(QListWidgetItem *item);
//    void newImgShowWin(ClickAbleQLabel* qlabel);


private:
    Ui::MainWindow *ui;
    ImageFormatConvert *InstanceofImgCvt;
    QGraphicsScene *scene;
    QStringList paths;
    QButtonGroup *ImgformatBtnGroup;
};

#endif // MAINWINDOW_H
