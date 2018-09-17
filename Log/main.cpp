#include <QCoreApplication>
#include <QDebug>
#include <QDebugStateSaver>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qputenv("QT_MESSAGE_PATTERN", "[%{type}] %{appname} (%{file}:%{line}) - %{message}");

    qDebug() << "Hello qdebug";

    qInfo() << "Info message with \n new line";

    QString text = "string text";

    QDebugStateSaver saver(qDebug().noquote());
    qCritical().noquote() << "wow , critical " << text;

    qDebug() << "wow , critical " << text;

    return a.exec();
}
