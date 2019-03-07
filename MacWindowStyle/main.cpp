#include "mainwindow.h"
#include <QApplication>
#include <QStyledItemDelegate>
#include "customstylewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    CustomStyleWidget widget;
    MoveWidgetOnTop(&widget);
    widget.setAttribute(Qt::WA_TranslucentBackground, true);
    widget.show();

    return a.exec();
}
