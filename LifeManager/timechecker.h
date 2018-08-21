#ifndef TIMECHECKER_H
#define TIMECHECKER_H

#include <QObject>
#include <QTimer>

class TimeChecker : public QObject
{
    Q_OBJECT
public:
    explicit TimeChecker(QObject *parent = nullptr);

    void startCheck();

signals:

    void showQuestions();

public slots:

    void onTimerTimeOut();

private:
    QTimer m_timer;
};

#endif // TIMECHECKER_H
