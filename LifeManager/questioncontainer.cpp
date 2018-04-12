#include "questioncontainer.h"
#include "ui_questioncontainer.h"
#include <QProcess>
#include <QVBoxLayout>
#include <QKeyEvent>
#include "questionitemwidget.h"
#include "questionmanager.h"

using namespace std;

QuestionContainer::QuestionContainer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionContainer)
{
    ui->setupUi(this);        
}

QuestionContainer::~QuestionContainer()
{
    delete ui;
}

void QuestionContainer::initQuestionList()
{
    QVBoxLayout *lay = new QVBoxLayout(ui->scrollAreaWidgetContents);

    QuestionManager manager;
    const list<pair<string, string>> &quelist = manager.getQuestionList();
    for (const pair<string, string> &qes : quelist) {
        QuestionItemWidget *pwgt = new QuestionItemWidget(ui->scrollAreaWidgetContents);
        pwgt->initQuestion(qes.first, qes.second);
        lay->addWidget(pwgt);
        m_widgetlist.push_back(pwgt);
    }
}

void QuestionContainer::showQuestions()
{
    showFullScreen();
    for (QuestionItemWidget *pwgt : m_widgetlist) {
        pwgt->clearAnswer();
    }
}

void QuestionContainer::closeEvent(QCloseEvent *ev)
{
    ev->ignore();
}

void QuestionContainer::on_pushButtonShutdown_clicked()
{
    QProcess::startDetached("shutdown -s -f -t 00");
}

void QuestionContainer::on_pushButtonOK_clicked()
{
    bool allright = true;
    for (QuestionItemWidget *pwgt : m_widgetlist) {
        allright &= pwgt->isAnswerRight();
    }
    if (allright){
        hide();
    }
}
