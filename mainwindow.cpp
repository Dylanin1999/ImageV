#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <stdlib.h>
#include <QDebug>
#include <QDragEnterEvent>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pathline->setAcceptDrops(true);
    ImgformatBtnGroup = new QButtonGroup(this);
    ImgformatBtnGroup->addButton(ui->NV12Button,0);
    ImgformatBtnGroup->addButton(ui->NV21Button,1);
    ImgformatBtnGroup->addButton(ui->I444Button,2);
    ImgformatBtnGroup->addButton(ui->YV24Button,3);
    ui->NV12Button->setChecked(true);

    connect(ui->pathbutton,&QPushButton::clicked,[=](){

        QStringList paths = QFileDialog::getOpenFileNames(this,"打开文件","C:\\Users");
        QString path;
        for(int i=0;i<paths.size();i++)
        {
            path+=paths[i]+";";
        }
        ui->pathline->setText(path);
        connect(ui->modifyBtn,&QPushButton::clicked,[=](){
            QString postfix = ui->postfix_textline->text();
            if(postfix!=nullptr)
            {
                NameChange *InstanceofNameChange = new NameChange();
                InstanceofNameChange->ChangePostfix(paths,postfix.toStdString());
                delete InstanceofNameChange;
            }
        });

        connect(ui->TransBtn,&QPushButton::clicked,[=](){

            ImageFormatConvert *InstanceofImgCvt = new ImageFormatConvert();

            switch (ImgformatBtnGroup->checkedId())
            {
                case 0:
                InstanceofImgCvt->NV12ToJpg(paths,2056,1600,1600);
                break;
                case 1:
                InstanceofImgCvt->NV21ToJpg(paths,2056,1600,1600);
                break;
                case 2:
                InstanceofImgCvt->I444ToJpg(paths,2056,1600,1600);
                break;
                case 3:
                InstanceofImgCvt->YV24ToJpg(paths,2056,1600,1600);
                break;
            }

            delete InstanceofImgCvt;

        });


    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    //对拖放事件进行筛选
    if (true)
    {
        e->acceptProposedAction();	//放行，否则不会执行dropEvent()函数
    }
}

void MainWindow::dropEvent(QDropEvent *e)
{
    QList<QUrl> urls = e->mimeData()->urls();
    if(urls.isEmpty())
        return ;
    qDebug()<< urls.size();
    foreach (QUrl u, urls)
    {
        QString filepath = u.toLocalFile();
        filepath += ";";
        qDebug()<<"filepath: "<<filepath;
        paths.append(filepath);
    }
    //去掉重复路径
    paths = paths.toSet().toList();
    ui->pathline->clear();
    for(int i=0;i<paths.size();++i)
    {
        QString path = paths.at(i);
        path += ";";
        qDebug()<<"Path: "<<path;
        ui->pathline->append(path);
    }
}





