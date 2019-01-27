#include <QCoreApplication>
#include <QDebug>
#include <QDebugStateSaver>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    qputenv("QT_MESSAGE_PATTERN", "[%{type}] %{appname} (%{file}:%{line}) - %{message}");

//    qDebug() << "Hello qdebug";

//    qInfo() << "Info message with \n new line";

//    QString text = "string text";

//    QDebugStateSaver saver(qDebug().noquote());
//    qCritical().noquote() << "wow , critical " << text;

    QObject *obj1 = new QObject();
    QObject *obj2 = new QObject();
    QObject *obj3 = nullptr;
    QObject::connect(obj1, &QObject::destroyed, obj2, &QObject::destroyed);
    QObject::connect(obj3, &QObject::destroyed, obj2, &QObject::destroyed);
    QObject::connect(obj1, &QObject::destroyed, obj3, &QObject::destroyed);

//    qDebug() << "wow , critical " << text;

    return a.exec();
}
