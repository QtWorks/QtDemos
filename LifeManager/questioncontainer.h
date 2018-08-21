#ifndef QUESTIONCONTAINER_H
#define QUESTIONCONTAINER_H

#include <QWidget>
#include <list>

namespace Ui {
class QuestionContainer;
}

class QuestionContainer : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionContainer(QWidget *parent = 0);
    ~QuestionContainer();

    void initQuestionList();

public slots:
    void showQuestions();

protected:
    void closeEvent(QCloseEvent *ev) override;

private slots:
    void on_pushButtonShutdown_clicked();

    void on_pushButtonOK_clicked();

private:
    Ui::QuestionContainer *ui;
    std::list<class QuestionItemWidget *> m_widgetlist;
};

#endif // QUESTIONCONTAINER_H
