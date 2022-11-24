#-------------------------------------------------
#
# Project created by QtCreator 2021-07-19T20:22:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToolProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += D:\Software\opencv-4.6.0\opencv46Mscv\build\install\include \
               D:\Software\opencv-4.6.0\opencv46Mscv\build\install\include\opencv2 \
                ./jpeglib/Release/include
LIBS += D:\Software\opencv-4.6.0\opencv46Mscv\build\lib\libopencv_*.dll.a \
        C:\Users\One\Downloads\YUVViewer4Linux-master\YUVViewer4Linux-master\jpeglib\Release\x64\jpeg.lib
CONFIG += c++11

SOURCES += \
    imgshowwidget.cpp \
        main.cpp \
        mainwindow.cpp \
    namechange.cpp \
    imageformatconvert.cpp

HEADERS += \
    imgshowwidget.h \
        mainwindow.h \
    namechange.h \
    imageformatconvert.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
