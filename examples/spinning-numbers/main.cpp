#include "mainwindow.h"
#include "testwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    TestWidget Tw(&w, qsf::QVector2u(0, 0), qsf::QVector2u(400, 300));
    Tw.show();

    return a.exec();
}
