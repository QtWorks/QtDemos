#ifndef QUESTIONMANAGER_H
#define QUESTIONMANAGER_H

#include <list>
#include <string>
//#include <

using namespace std;

class QuestionManager
{
public:
    QuestionManager();

    const list<pair<string, string>>& getQuestionList();

private:
    list<pair<string, string>> m_list;
};

#endif // QUESTIONMANAGER_H
