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
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QListWidget>
#include <QObject>

void MainWindow::OnListWidgetDoubleClicked(QListWidgetItem* item)
{
    qDebug()<<"Click! index is :"<<item->whatsThis();
    QWidget *NewImgWindows = new QWidget();
    QPixmap pic;
    pic.load(paths[item->whatsThis().toInt()]);

    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(pic));
    NewImgWindows->setPalette(palette);
    NewImgWindows->show();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ImageV");
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(255, 255, 255));
//    ui->ImgWindows->setPalette(palette);
//    ui->ImgWindows->setAutoFillBackground(true);

    ui->pathline->setAcceptDrops(true);
    ImgformatBtnGroup = new QButtonGroup(this);
    ImgformatBtnGroup->addButton(ui->NV12Button,NV12);
    ImgformatBtnGroup->addButton(ui->NV21Button,NV21);
    ImgformatBtnGroup->addButton(ui->I444Button,I444);
    ImgformatBtnGroup->addButton(ui->YV24Button,YV24);
    ImgformatBtnGroup->addButton(ui->JPGButton,JPG);
    ui->NV12Button->setChecked(true);
    InstanceofImgCvt = new ImageFormatConvert();
    QGraphicsScene *scene = new QGraphicsScene;
    QRegularExpression regExp("[0-9]+$");
    QValidator *validator = new QRegularExpressionValidator(regExp, this );

    ui->ImgH->setValidator(validator);
    ui->ImgW->setValidator(validator);
    QStringList fileTypeList = {"nv12","nv21","i444","yv24","jpg"};

    ui->ImgH->setText("0");
    ui->ImgW->setText("0");
    ui->ImgStride->setText("0");

    connect(ui->ImgW,&QLineEdit::textChanged,[=]()
    {
       QString ImgWidth = ui->ImgW->text();
       ui->ImgStride->setText(ImgWidth);
    });

    connect(ui->pathbutton,&QPushButton::clicked,[=](){

        paths = QFileDialog::getOpenFileNames(this,"打开文件","C:\\Users");
        QString path;
        for(int i=0;i<paths.size();i++)
        {
            path+=paths[i]+";";
        }
        ui->pathline->setText(path);

        QStringList splitList = paths[0].split(".");
        QString fileSuffixes = splitList[splitList.size()-1];
        qDebug()<<"fileSuffixes is "<<fileSuffixes;
        int fileIndex = fileTypeList.indexOf(fileSuffixes.toLower());
        switch (fileIndex)
        {
            case(0):
                ui->NV12Button->setChecked(true);
                break;
            case(1):
                ui->NV21Button->setChecked(true);
                break;
            case(2):
                ui->I444Button->setChecked(true);
                break;
            case(3):
                ui->YV24Button->setChecked(true);
                break;
            case(4):
                ui->JPGButton->setChecked(true);
                break;
            default:
                ui->NV12Button->setChecked(true);
            break;
        }

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

            InstanceofImgCvt->ImgW = ui->ImgW->text().toInt();
            InstanceofImgCvt->ImgH = ui->ImgH->text().toInt();
            InstanceofImgCvt->ImgStride = ui->ImgStride->text().toInt();

            if(InstanceofImgCvt->ImgW==0||InstanceofImgCvt->ImgH==0||InstanceofImgCvt->ImgStride==0)
                QMessageBox::critical(this, tr("Waring"),  tr("Please Check Image Size!"), QMessageBox::Discard,  QMessageBox::Discard);
            else
            {
                cv::Mat(InstanceofImgCvt->ImgH,InstanceofImgCvt->ImgW,CV_8UC3).copyTo(InstanceofImgCvt->jpgImg);
                int ratio = ui->ImgList->size().width()/3;
                qDebug()<<"ratio is "<<ratio;
                ui->ImgList->setViewMode(QListWidget::IconMode);
                ui->ImgList->setSpacing(10);
                ui->ImgList->setResizeMode(QListView::Adjust);
                ui->ImgList->setMovement(QListView::Free);
                ui->ImgList->setIconSize(QSize(ratio*1.5, ratio*1.5));

                for(int i=0;i<paths.size();i++)
                {
                    std::string path = paths[i].toStdString();
                    switch (ImgformatBtnGroup->checkedId())
                    {
                        case NV12:
                        InstanceofImgCvt->NV12ToJpg(path,InstanceofImgCvt->ImgH,InstanceofImgCvt->ImgW,InstanceofImgCvt->ImgStride);
                        break;
                        case NV21:
                        InstanceofImgCvt->NV21ToJpg(path,InstanceofImgCvt->ImgH,InstanceofImgCvt->ImgW,InstanceofImgCvt->ImgStride);
                        break;
                        case I444:
                        InstanceofImgCvt->I444ToJpg(path,InstanceofImgCvt->ImgH,InstanceofImgCvt->ImgW,InstanceofImgCvt->ImgStride);
                        break;
                        case YV24:
                        InstanceofImgCvt->YV24ToJpg(path,InstanceofImgCvt->ImgH,InstanceofImgCvt->ImgW,InstanceofImgCvt->ImgStride);
                        break;
                        case JPG:
                        InstanceofImgCvt->JpgToJpg(path,InstanceofImgCvt->ImgH,InstanceofImgCvt->ImgW,InstanceofImgCvt->ImgStride);
                        break;
                    }
                    if(ImgformatBtnGroup->checkedId()!=JPG)
                        InstanceofImgCvt->myQImage = QImage((const unsigned char*)InstanceofImgCvt->jpgImg.data,
                                                                                  InstanceofImgCvt->jpgImg.cols,
                                                                                  InstanceofImgCvt->jpgImg.rows,
                                                                                  InstanceofImgCvt->jpgImg.cols * 3, QImage::Format_RGB888);

                    QIcon icon;
                    QListWidgetItem *imageItem = new QListWidgetItem;
                    imageItem->setWhatsThis( QString::number(i));
                    icon.addPixmap(QPixmap::fromImage(InstanceofImgCvt->myQImage));
                    imageItem->setIcon(icon);
                    ui->ImgList->addItem(imageItem);
                    qDebug()<<"What is this "<<imageItem->whatsThis();

                }
            }
        });
    });
    connect(ui->ImgList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(OnListWidgetDoubleClicked(QListWidgetItem*)));
}



MainWindow::~MainWindow()
{
    delete InstanceofImgCvt;
    delete scene;
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
    QSet<QString> aSet(paths.begin(), paths.end());
  //  paths = aSet.toList();
    ui->pathline->clear();
    for(int i=0;i<paths.size();++i)
    {
        QString path = paths.at(i);
        path += ";";
        qDebug()<<"Path: "<<path;
        ui->pathline->append(path);
    }
}





