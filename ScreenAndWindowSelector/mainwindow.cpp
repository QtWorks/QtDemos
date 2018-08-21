#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::setPixmap(const QPixmap &pix)
{
    ui->label->setPixmap(pix);
    ui->label->setMinimumSize(pix.size());
}

void MainWindow::checkCursorPosition()
{

}
