#include <QCoreApplication>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QDebug>
#include <QMetaObject>
#include "runobject.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RunObject obj1;
    RunObject obj2;
    RunObject obj3;

    QThread thread1;
    QThread thread2;
    QThread thread3;

    thread1.start();
    thread2.start();
    thread3.start();

    obj1.moveToThread(&thread1);
    obj2.moveToThread(&thread2);
    obj3.moveToThread(&thread3);

    qDebug() << "start multi jobs";

    QMetaObject::invokeMethod(&obj1, "startRunAndLock");
    QMetaObject::invokeMethod(&obj2, "startRunAndLock");
    QMetaObject::invokeMethod(&obj3, "startRunAndLock");

    return a.exec();
}
