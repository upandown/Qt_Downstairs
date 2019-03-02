#-------------------------------------------------
#
# Project created by QtCreator 2017-08-15T14:09:21
#
#-------------------------------------------------

QT       += multimedia
QT       += core gui
RC_FILE += icotest.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homework-final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    second.cpp \
    board.cpp \
    mywidget.cpp \
    normalban.cpp \
    gameover.cpp \
    list.cpp

HEADERS  += mainwindow.h \
    form.h \
    second.h \
    board.h \
    mywidget.h \
    normalban.h \
    gameover.h \
    list.h

FORMS    += mainwindow.ui \
    form.ui \
    second.ui \
    gameover.ui \
    list.ui

DISTFILES += \
    icotest.rc
