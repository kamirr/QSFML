#include "mainwindow.h"
#include <QApplication>

#include "QSFML/qvector2.hpp"
#include "datewidget.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DateWidget date(&w, qsf::QVector2i(0, 0), qsf::QVector2i(450, 75));
    date.show();

    return a.exec();
}
