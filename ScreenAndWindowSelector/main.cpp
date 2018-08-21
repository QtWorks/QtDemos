#include "mainwindow.h"
#include <QApplication>
#include <QWindow>
#include <QDebug>
#include <QImage>
#include <QDesktopWidget>
#include <QScreen>
#include "machelper.h"
#include "widgetborder.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<QPair<long, QRect>> windows;
    GetAllWindows(windows);

//    MainWindow w;
//    w.show();

//    for (long winid : windows) {
//        qDebug() << "process window " << winid;
//        QWindow *pwindow = QWindow::fromWinId((WId)winid);
//        if (pwindow) {
//            qDebug() << "window found " << pwindow->geometry();
//        }
//    }

    bool isRetinaMain = QApplication::primaryScreen()->devicePixelRatio() > 1;
    MessageBride *bridge = new MessageBride();
    QList<QScreen*> screens = a.screens();
    for (int i = 0; i < screens.count(); ++i) {
        QScreen* screen = screens.at(i);
        QRect geom = screen->geometry();
#ifdef Q_OS_MAC
        QPixmap shotPix = grabWindow(QApplication::desktop()->winId(), geom.x(), geom.y(), geom.width(), geom.height(), isRetinaMain, screen->devicePixelRatio());
#else
        QPixmap shotPix = screen->grabWindow(QApplication::desktop()->winId(), geom.x(), geom.y(), geom.width(), geom.height());
#endif
        shotPix.setDevicePixelRatio(screen->devicePixelRatio());

        WidgetSelector *wgt = new WidgetSelector(nullptr);
        QObject::connect(wgt, &WidgetSelector::windowSelected, bridge, &MessageBride::finish);
        QObject::connect(bridge, &MessageBride::finish, wgt, &WidgetSelector::stopWindowCheck);
        wgt->setGeometry(screen->geometry());
        wgt->initPixmap(shotPix, windows);
#ifdef Q_OS_MAC
        MoveWidgetOnTop(wgt);
#endif
        wgt->show();

    }

    return a.exec();
}
