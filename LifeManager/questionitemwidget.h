#ifndef QUESTIONITEMWIDGET_H
#define QUESTIONITEMWIDGET_H

#include <QWidget>

namespace Ui {
class QuestionItemWidget;
}

using namespace std;

class QuestionItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionItemWidget(QWidget *parent = 0);
    ~QuestionItemWidget();

    void initQuestion(const string &question, const string &answer);
    bool isAnswerRight();
    void clearAnswer();

private:
    Ui::QuestionItemWidget *ui;
    string m_answer;
};

#endif // QUESTIONITEMWIDGET_H
