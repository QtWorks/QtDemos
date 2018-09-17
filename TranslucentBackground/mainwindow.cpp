#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

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
//    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    QLabel *plabel = new QLabel(this);
    plabel->setMinimumSize(200, 200);
    plabel->setStyleSheet("background-color:red");
    plabel->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    setAttribute(Qt::WA_TranslucentBackground, true);
}
