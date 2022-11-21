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
#include <QtWidgets/QGraphicsView>
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
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout1;
    QTextEdit *pathline;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pathbutton;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *ImgWindows;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QPushButton *TransBtn;
    QVBoxLayout *verticalLayout;
    QRadioButton *NV12Button;
    QRadioButton *NV21Button;
    QRadioButton *I444Button;
    QRadioButton *YV24Button;
    QRadioButton *JPGButton;
    QGridLayout *gridLayout;
    QLabel *ImgS;
    QLineEdit *ImgStride;
    QLabel *ImgWidth;
    QLabel *ImgHeight;
    QLineEdit *ImgH;
    QLineEdit *ImgW;
    QHBoxLayout *horizontalLayout;
    QLineEdit *postfix_textline;
    QPushButton *modifyBtn;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(668, 631);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout1 = new QHBoxLayout();
        horizontalLayout1->setSpacing(6);
        horizontalLayout1->setObjectName("horizontalLayout1");
        pathline = new QTextEdit(centralWidget);
        pathline->setObjectName("pathline");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pathline->sizePolicy().hasHeightForWidth());
        pathline->setSizePolicy(sizePolicy);
        pathline->setMaximumSize(QSize(16777215, 20));

        horizontalLayout1->addWidget(pathline);

        horizontalSpacer_3 = new QSpacerItem(10, 10, QSizePolicy::Ignored, QSizePolicy::Minimum);

        horizontalLayout1->addItem(horizontalSpacer_3);

        pathbutton = new QPushButton(centralWidget);
        pathbutton->setObjectName("pathbutton");

        horizontalLayout1->addWidget(pathbutton);


        verticalLayout_3->addLayout(horizontalLayout1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ImgWindows = new QGraphicsView(centralWidget);
        ImgWindows->setObjectName("ImgWindows");

        horizontalLayout_2->addWidget(ImgWindows);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        TransBtn = new QPushButton(centralWidget);
        TransBtn->setObjectName("TransBtn");

        gridLayout_2->addWidget(TransBtn, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        NV12Button = new QRadioButton(centralWidget);
        NV12Button->setObjectName("NV12Button");

        verticalLayout->addWidget(NV12Button);

        NV21Button = new QRadioButton(centralWidget);
        NV21Button->setObjectName("NV21Button");

        verticalLayout->addWidget(NV21Button);

        I444Button = new QRadioButton(centralWidget);
        I444Button->setObjectName("I444Button");

        verticalLayout->addWidget(I444Button);

        YV24Button = new QRadioButton(centralWidget);
        YV24Button->setObjectName("YV24Button");

        verticalLayout->addWidget(YV24Button);

        JPGButton = new QRadioButton(centralWidget);
        JPGButton->setObjectName("JPGButton");

        verticalLayout->addWidget(JPGButton);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 2, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        ImgS = new QLabel(centralWidget);
        ImgS->setObjectName("ImgS");

        gridLayout->addWidget(ImgS, 2, 0, 1, 1);

        ImgStride = new QLineEdit(centralWidget);
        ImgStride->setObjectName("ImgStride");

        gridLayout->addWidget(ImgStride, 2, 1, 1, 1);

        ImgWidth = new QLabel(centralWidget);
        ImgWidth->setObjectName("ImgWidth");

        gridLayout->addWidget(ImgWidth, 0, 0, 1, 1);

        ImgHeight = new QLabel(centralWidget);
        ImgHeight->setObjectName("ImgHeight");

        gridLayout->addWidget(ImgHeight, 1, 0, 1, 1);

        ImgH = new QLineEdit(centralWidget);
        ImgH->setObjectName("ImgH");

        gridLayout->addWidget(ImgH, 1, 1, 1, 1);

        ImgW = new QLineEdit(centralWidget);
        ImgW->setObjectName("ImgW");

        gridLayout->addWidget(ImgW, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        postfix_textline = new QLineEdit(centralWidget);
        postfix_textline->setObjectName("postfix_textline");

        horizontalLayout->addWidget(postfix_textline);

        modifyBtn = new QPushButton(centralWidget);
        modifyBtn->setObjectName("modifyBtn");

        horizontalLayout->addWidget(modifyBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 30);

        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 668, 22));
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
        TransBtn->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242", nullptr));
        NV12Button->setText(QCoreApplication::translate("MainWindow", "NV12", nullptr));
        NV21Button->setText(QCoreApplication::translate("MainWindow", "NV21", nullptr));
        I444Button->setText(QCoreApplication::translate("MainWindow", "I444", nullptr));
        YV24Button->setText(QCoreApplication::translate("MainWindow", "YV24", nullptr));
        JPGButton->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        ImgS->setText(QCoreApplication::translate("MainWindow", "Stride", nullptr));
        ImgWidth->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        ImgHeight->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        modifyBtn->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\220\216\347\274\200", nullptr));
        label->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
