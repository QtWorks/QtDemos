#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkReply>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QNetworkReply *reply = access.get(QNetworkRequest(QUrl("http://127.0.0.1:5000")));
//    QNetworkReply *reply = access.get(QNetworkRequest(QUrl("http://www.baidu.com")));
    QObject::connect(reply, &QNetworkReply::finished, [=](){
        qDebug() << reply->readAll();
        reply->deleteLater();
    });
}
