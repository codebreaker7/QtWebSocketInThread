#-------------------------------------------------
#
# Project created by QtCreator 2018-11-05T19:14:38
#
#-------------------------------------------------

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWebSocketInThread
TEMPLATE = app
CCFLAG += -std=c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    websocketworker.cpp \
    websocketrunnable.cpp

HEADERS  += mainwindow.h \
    websocketworker.h \
    websocketrunnable.h

FORMS    += mainwindow.ui
