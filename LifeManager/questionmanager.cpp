#include "questionmanager.h"
#include <QString>

QuestionManager::QuestionManager()
{
    m_list.push_back(make_pair<string,string>("question1", QString::fromLocal8Bit("答案1").toStdString()));
    m_list.push_back(make_pair<string,string>("question2", QString::fromLocal8Bit("答案2").toStdString()));
    m_list.push_back(make_pair<string,string>("question3", QString::fromLocal8Bit("答案3").toStdString()));
    m_list.push_back(make_pair<string,string>("question4", QString::fromLocal8Bit("答案4").toStdString()));
    m_list.push_back(make_pair<string,string>("question5", QString::fromLocal8Bit("答案5").toStdString()));
}

const list<pair<string, string> > &QuestionManager::getQuestionList()
{
    return m_list;
}
