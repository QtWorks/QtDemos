#ifndef RUNOBJECT_H
#define RUNOBJECT_H

#include <QObject>

class RunObject : public QObject
{
    Q_OBJECT
public:
    explicit RunObject(QObject *parent = 0);

signals:

public slots:
    void startRunAndLock();

private:
    QString m_uuid;
};

#endif // RUNOBJECT_H
