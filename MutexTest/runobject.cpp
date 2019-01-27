#include "runobject.h"
#include <QMutex>
#include <QMutexLocker>
#include <QUuid>
#include <QThread>
#include <QDebug>

QMutex global_mutex;

RunObject::RunObject(QObject *parent) : QObject(parent)
{
    m_uuid = QUuid().createUuid().toString();
}

void RunObject::startRunAndLock()
{
    qDebug() << m_uuid << " before get mutext";
    QMutexLocker locker(&global_mutex);
    qDebug() << m_uuid << " now get mutext";

    QThread::currentThread()->sleep(10);

    qDebug() << m_uuid << " after long time work, release mutex";
}
