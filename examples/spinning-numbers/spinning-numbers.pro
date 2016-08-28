# =========================================================== #
# QSFML (c) Kamil Koczurek | koczurekk@gmail.com	      	  #
# GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html #
# =========================================================== #

DESTDIR=build
OBJECTS_DIR=build/obj

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
