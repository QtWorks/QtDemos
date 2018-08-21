#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QVBoxLayout>

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

void MainWindow::setWidgetSize()
{
    resize(600, 400);
    QSplitter *psplitter = new QSplitter(ui->centralWidget);
    QVBoxLayout *playout = new QVBoxLayout(ui->centralWidget);
    playout->setContentsMargins(0, 0, 0, 0);
    playout->addWidget(psplitter);

    QWidget *wgt1 = new QWidget(psplitter);
    QWidget *wgt2 = new QWidget(psplitter);
    psplitter->addWidget(wgt1);
    psplitter->addWidget(wgt2);

    psplitter->setOrientation(Qt::Horizontal);

    QList<int> sizes;
    sizes << 400 << 200;
    psplitter->setSizes(sizes);
}
