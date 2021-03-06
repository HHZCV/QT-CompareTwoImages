#-------------------------------------------------
#
# Project created by QtCreator 2017-12-09T02:43:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestOpencv
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


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
    cvimagewidget.h

FORMS += \
        mainwindow.ui
INCLUDEPATH += C:\Users\huzhu\opencv3.1.0\opencv\build\qt_ming_build\install\include

LIBS += C:\Users\huzhu\opencv3.1.0\opencv\build\qt_ming_build\install\x86\mingw\bin\libopencv_core310.dll
LIBS += C:\Users\huzhu\opencv3.1.0\opencv\build\qt_ming_build\install\x86\mingw\bin\libopencv_highgui310.dll
LIBS += C:\Users\huzhu\opencv3.1.0\opencv\build\qt_ming_build\install\x86\mingw\bin\libopencv_imgcodecs310.dll
LIBS += C:\Users\huzhu\opencv3.1.0\opencv\build\qt_ming_build\install\x86\mingw\bin\libopencv_imgproc310.dll
LIBS += C:\Users\huzhu\opencv3.1.0\opencv\build\qt_ming_build\install\x86\mingw\bin\libopencv_features2d310.dll
LIBS += C:\Users\huzhu\opencv3.1.0\opencv\build\qt_ming_build\install\x86\mingw\bin\libopencv_calib3d310.dll
