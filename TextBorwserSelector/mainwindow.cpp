#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include "textbrowseritem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *playout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    TextBrowserItem *browser1 = new TextBrowserItem(ui->scrollAreaWidgetContents);
    browser1->setReadOnly(true);
    browser1->setMaximumHeight(50);
    browser1->setText("这是第一条消息这是第一条消息这是第一条消息这是第一条消息这是第一条消息这是第一条消息这是第一条消息这是第一条消息这是第一条消息");
    playout->addWidget(browser1);
    TextBrowserItem *browser2 = new TextBrowserItem(ui->scrollAreaWidgetContents);
    browser2->setReadOnly(true);
    browser2->setMaximumHeight(50);
    browser2->setText("这是第二条消息这是第二条消息这是第二条消息这是第二条消息这是第二条消息这是第二条消息这是第二条消息这是第二条消息这是第二条消息");
    playout->addWidget(browser2);
    TextBrowserItem *browser3 = new TextBrowserItem(ui->scrollAreaWidgetContents);
    browser3->setReadOnly(true);
    browser3->setMaximumHeight(50);
    browser3->setText("这是第三条消息这是第三条消息这是第三条消息这是第三条消息这是第三条消息这是第三条消息这是第三条消息这是第三条消息这是第三条消息");
    playout->addWidget(browser3);
    TextBrowserItem *browser4 = new TextBrowserItem(ui->scrollAreaWidgetContents);
    browser4->setReadOnly(true);
    browser4->setMaximumHeight(50);
    browser4->setText("这是第四条消息这是第四条消息这是第四条消息这是第四条消息这是第四条消息这是第四条消息这是第四条消息这是第四条消息这是第四条消息");
    playout->addWidget(browser4);
    TextBrowserItem *browser5 = new TextBrowserItem(ui->scrollAreaWidgetContents);
    browser5->setReadOnly(true);
    browser5->setMaximumHeight(50);
    browser5->setText("这是第五条消息这是第五条消息这是第五条消息这是第五条消息这是第五条消息这是第五条消息这是第五条消息这是第五条消息这是第五条消息");
    playout->addWidget(browser5);

    ui->scrollAreaWidgetContents->addItem(browser1);
    ui->scrollAreaWidgetContents->addItem(browser2);
    ui->scrollAreaWidgetContents->addItem(browser3);
    ui->scrollAreaWidgetContents->addItem(browser4);
    ui->scrollAreaWidgetContents->addItem(browser5);
}

MainWindow::~MainWindow()
{
    delete ui;
}
