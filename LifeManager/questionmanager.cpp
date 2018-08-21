#include "questionmanager.h"
#include <QString>

QuestionManager::QuestionManager()
{
    m_list.push_back(make_pair<string,string>(QString::fromLocal8Bit("因何而修行？").toStdString(), QString::fromLocal8Bit("大自在").toStdString()));
    m_list.push_back(make_pair<string,string>(QString::fromLocal8Bit("如何能在业海中遨游？").toStdString(), QString::fromLocal8Bit("神通自在").toStdString()));
    m_list.push_back(make_pair<string,string>(QString::fromLocal8Bit("神通的基础是什么？").toStdString(), QString::fromLocal8Bit("定力").toStdString()));
    m_list.push_back(make_pair<string,string>(QString::fromLocal8Bit("无尽苍穹海").toStdString(), QString::fromLocal8Bit("漫漫长生路").toStdString()));
    m_list.push_back(make_pair<string,string>(QString::fromLocal8Bit("要关机开始练习吗？").toStdString(), QString::fromLocal8Bit("好").toStdString()));
}

const list<pair<string, string> > &QuestionManager::getQuestionList()
{
    return m_list;
}
