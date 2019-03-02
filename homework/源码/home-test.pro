#-------------------------------------------------
#
# Project created by QtCreator 2017-08-31T17:02:23
#
#-------------------------------------------------
QT       += widgets
QT       += core gui
QT       += multimedia
CONFIG += resources_big
RC_FILE += icotest.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = home-test
TEMPLATE = app


SOURCES += main.cpp\
    board.cpp \
    form.cpp \
    gameover.cpp \
    list.cpp \
    mainwindow.cpp \
    mywidget.cpp \
    normalban.cpp \
    second.cpp

HEADERS  += \
    board.h \
    form.h \
    gameover.h \
    GBK.h \
    list.h \
    mainwindow.h \
    mywidget.h \
    normalban.h \
    second.h

FORMS    += \
    form.ui \
    gameover.ui \
    list.ui \
    mainwindow.ui \
    second.ui

SUBDIRS += \
    homework-final.pro

DISTFILES += \
    home-test.pro.user \
    homework-final.pro.user \
    hw.ico \
    icotest.rc

RESOURCES += \
    resource.qrc
