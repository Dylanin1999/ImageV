#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <namechange.h>
#include <imageformatconvert.h>
#include <QButtonGroup>
#include <QGraphicsScene>
#include <QListWidgetItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

private slots:
    void OnListWidgetDoubleClicked(QListWidgetItem *item);


private:
    Ui::MainWindow *ui;
    ImageFormatConvert *InstanceofImgCvt;
    QGraphicsScene *scene;
    QStringList paths;
    QButtonGroup *ImgformatBtnGroup;
};

#endif // MAINWINDOW_H
