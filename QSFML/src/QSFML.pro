# =========================================================== #
# QSFML (c) Kamil Koczurek | koczurekk@gmail.com	      	  #
# GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html #
# =========================================================== #

DESTDIR=build
OBJECTS_DIR=build/obj

TEMPLATE = lib
TARGET = QSFML
INCLUDEPATH += ../include/

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS     += -lsfml-graphics -lsfml-window -lsfml-system
QMAKE_CXXFLAGS += -std=c++11 -Wno-sign-compare

SOURCES += \
    keyconverter.cpp \
    qresourcestream.cpp \
    QSFMLCanvas.cpp \
    QSFMLCanvasEventHandler.cpp \
    string.cpp

HEADERS += \
    ../include/keyconverter.hpp \
    ../include/qresourcestream.hpp \
    ../include/QSFMLCanvas.hpp \
    ../include/qvector2.hpp \
    ../include/string.hpp
