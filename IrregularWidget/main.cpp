#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include "irregualarwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow window;
//    window.show();

    IrregualarWidget w;
    w.show();
    AllwaysOnTop(&w);
    QRect screen = a.primaryScreen()->geometry();
    w.setGeometry(300, 0, 400, 300);

    return a.exec();
}
