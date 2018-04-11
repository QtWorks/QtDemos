#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::ToolTip | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
    setWindowState(Qt::WindowFullScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}
