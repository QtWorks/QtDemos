#include "timechecker.h"
#include <QTime>

TimeChecker::TimeChecker(QObject *parent) : QObject(parent)
{
    connect(&m_timer, &QTimer::timeout, this, &TimeChecker::onTimerTimeOut);
    m_timer.setSingleShot(true);
}

void TimeChecker::startCheck()
{
    QTime tm = QTime::currentTime();
    //下午2个小时检查一次
    if (tm.hour() > 10 && tm.hour() < 22) {
        m_timer.start(2 * 60 * 60 * 1000);
    } else if (tm.hour() > 22) {
        m_timer.start(60 * 60 * 1000);
    } else if (tm.hour() < 10) {
        //12点之后10分钟提示一次
        m_timer.start(10 * 60 * 1000);
    }
}

void TimeChecker::onTimerTimeOut()
{
    emit showQuestions();

    startCheck();
}
