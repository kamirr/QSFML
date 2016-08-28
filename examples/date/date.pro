# =========================================================== #
# QSFML (c) Kamil Koczurek | koczurekk@gmail.com	      	  #
# GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html #
# =========================================================== #

DESTDIR=build
OBJECTS_DIR=build/obj

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
