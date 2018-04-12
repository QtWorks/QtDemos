#include "questionitemwidget.h"
#include "ui_questionitemwidget.h"

QuestionItemWidget::QuestionItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionItemWidget)
{
    ui->setupUi(this);
}

QuestionItemWidget::~QuestionItemWidget()
{
    delete ui;
}

void QuestionItemWidget::initQuestion(const string &question, const string &answer)
{
    ui->textEditQuestion->setText(QString::fromStdString(question));
    m_answer = answer;
}

bool QuestionItemWidget::isAnswerRight()
{
    string str = ui->textEditAnswer->toPlainText().toStdString();
    return str == m_answer;
}

void QuestionItemWidget::clearAnswer()
{
    ui->textEditAnswer->clear();
}
