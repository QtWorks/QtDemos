#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    Form fm;
    fm.show();

    qDebug() << "window id " << fm.winId();

    return a.exec();
}
