#include "mainwindow.h"
#include <QApplication>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.connectToServer(QUrl(QStringLiteral("ws://140.143.18.162:8888/chatsocket")));

    return a.exec();
}
