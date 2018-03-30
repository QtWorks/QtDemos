#include <QCoreApplication>
#include <QRegExp>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QRegExp rx("<.*?>");
    QString str = "<presence><c xmlns='http://jabber.org/protocol/caps' hash='sha-1' node='https://github.com/qxmpp-project/qxmpp' ver='k38SC26p638xIKXIi2zPpblrpfo='/></presence>";
    QStringList list;
    int pos = 0;

    while ((pos = rx.indexIn(str, pos)) != -1) {
        list << rx.cap(1);
        pos += rx.matchedLength();
    }
    qDebug() << list;

    return a.exec();
}
