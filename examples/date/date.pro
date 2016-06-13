#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T14:35:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += /usr/include

LIBS += -lQSFML -lsfml-graphics -lsfml-window -lsfml-system
QMAKE_CXXFLAGS += -std=gnu++11

TARGET = date
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    datewidget.cpp

HEADERS  += mainwindow.h \
    datewidget.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    resources/resources.qrc
