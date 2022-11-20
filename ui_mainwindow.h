/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout1;
    QTextEdit *pathline;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pathbutton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *postfix_textline;
    QPushButton *modifyBtn;
    QPushButton *TransBtn;
    QLabel *ImgWindows;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *ImgS;
    QLineEdit *ImgStride;
    QLabel *ImgWidth;
    QLabel *ImgHeight;
    QLineEdit *ImgH;
    QLineEdit *ImgW;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QRadioButton *NV12Button;
    QRadioButton *NV21Button;
    QRadioButton *I444Button;
    QRadioButton *YV24Button;
    QRadioButton *JPGButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(731, 570);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 10, 671, 31));
        horizontalLayout1 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout1->setSpacing(6);
        horizontalLayout1->setContentsMargins(11, 11, 11, 11);
        horizontalLayout1->setObjectName("horizontalLayout1");
        horizontalLayout1->setContentsMargins(0, 0, 0, 0);
        pathline = new QTextEdit(horizontalLayoutWidget);
        pathline->setObjectName("pathline");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pathline->sizePolicy().hasHeightForWidth());
        pathline->setSizePolicy(sizePolicy);
        pathline->setMaximumSize(QSize(16777215, 100));

        horizontalLayout1->addWidget(pathline);

        horizontalSpacer_3 = new QSpacerItem(10, 10, QSizePolicy::Ignored, QSizePolicy::Minimum);

        horizontalLayout1->addItem(horizontalSpacer_3);

        pathbutton = new QPushButton(horizontalLayoutWidget);
        pathbutton->setObjectName("pathbutton");

        horizontalLayout1->addWidget(pathbutton);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(480, 220, 241, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        postfix_textline = new QLineEdit(layoutWidget);
        postfix_textline->setObjectName("postfix_textline");

        horizontalLayout_2->addWidget(postfix_textline);

        modifyBtn = new QPushButton(layoutWidget);
        modifyBtn->setObjectName("modifyBtn");

        horizontalLayout_2->addWidget(modifyBtn);

        TransBtn = new QPushButton(centralWidget);
        TransBtn->setObjectName("TransBtn");
        TransBtn->setGeometry(QRect(630, 180, 75, 23));
        ImgWindows = new QLabel(centralWidget);
        ImgWindows->setObjectName("ImgWindows");
        ImgWindows->setGeometry(QRect(20, 80, 451, 461));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(550, 70, 171, 99));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ImgS = new QLabel(layoutWidget1);
        ImgS->setObjectName("ImgS");

        gridLayout->addWidget(ImgS, 2, 0, 1, 1);

        ImgStride = new QLineEdit(layoutWidget1);
        ImgStride->setObjectName("ImgStride");

        gridLayout->addWidget(ImgStride, 2, 1, 1, 1);

        ImgWidth = new QLabel(layoutWidget1);
        ImgWidth->setObjectName("ImgWidth");

        gridLayout->addWidget(ImgWidth, 0, 0, 1, 1);

        ImgHeight = new QLabel(layoutWidget1);
        ImgHeight->setObjectName("ImgHeight");

        gridLayout->addWidget(ImgHeight, 1, 0, 1, 1);

        ImgH = new QLineEdit(layoutWidget1);
        ImgH->setObjectName("ImgH");

        gridLayout->addWidget(ImgH, 1, 1, 1, 1);

        ImgW = new QLineEdit(layoutWidget1);
        ImgW->setObjectName("ImgW");

        gridLayout->addWidget(ImgW, 0, 1, 1, 1);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(490, 70, 57, 126));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        NV12Button = new QRadioButton(layoutWidget2);
        NV12Button->setObjectName("NV12Button");

        verticalLayout->addWidget(NV12Button);

        NV21Button = new QRadioButton(layoutWidget2);
        NV21Button->setObjectName("NV21Button");

        verticalLayout->addWidget(NV21Button);

        I444Button = new QRadioButton(layoutWidget2);
        I444Button->setObjectName("I444Button");

        verticalLayout->addWidget(I444Button);

        YV24Button = new QRadioButton(layoutWidget2);
        YV24Button->setObjectName("YV24Button");

        verticalLayout->addWidget(YV24Button);

        JPGButton = new QRadioButton(layoutWidget2);
        JPGButton->setObjectName("JPGButton");

        verticalLayout->addWidget(JPGButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 731, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pathbutton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        modifyBtn->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\220\216\347\274\200", nullptr));
        TransBtn->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242", nullptr));
        ImgWindows->setText(QString());
        ImgS->setText(QCoreApplication::translate("MainWindow", "Stride", nullptr));
        ImgWidth->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        ImgHeight->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        NV12Button->setText(QCoreApplication::translate("MainWindow", "NV12", nullptr));
        NV21Button->setText(QCoreApplication::translate("MainWindow", "NV21", nullptr));
        I444Button->setText(QCoreApplication::translate("MainWindow", "I444", nullptr));
        YV24Button->setText(QCoreApplication::translate("MainWindow", "YV24", nullptr));
        JPGButton->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
