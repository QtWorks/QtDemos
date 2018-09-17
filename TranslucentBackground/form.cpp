#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
//    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    update();
}

void Form::on_pushButton_2_clicked()
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    update();
}

void Form::on_pushButton_3_clicked()
{
    setWindowFlags(windowFlags() & Qt::NoDropShadowWindowHint);
}
