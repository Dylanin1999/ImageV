#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <namechange.h>
#include <imageformatconvert.h>
#include <QButtonGroup>
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

private:
    Ui::MainWindow *ui;
    ImageFormatConvert *InstanceofImgCvt;
    QStringList paths;
    QButtonGroup *ImgformatBtnGroup;
};

#endif // MAINWINDOW_H
