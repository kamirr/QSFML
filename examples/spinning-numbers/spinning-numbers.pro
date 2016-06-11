#-------------------------------------------------
#
# Project created by QtCreator 2016-05-02T12:52:23
#
#-------------------------------------------------

QT       += core gui
LIBS     += -lsfml-graphics -lsfml-window -lsfml-system -lQSFML
QMAKE_CXXFLAGS += -std=c++11 -Wno-sign-compare

INCLUDEPATH += /usr/include

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spinning-numbers
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    testwidget.cpp
    testwidget.cpp

HEADERS  += mainwindow.h \
    testwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/resources.qrc
