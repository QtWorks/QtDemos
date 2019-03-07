#include "customstylewidget.h"
#include "ui_customstylewidget.h"

CustomStyleWidget::CustomStyleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomStyleWidget)
{
    ui->setupUi(this);

    setWindowFlags(
                #ifdef Q_OS_MAC
                    Qt::SubWindow |
                #else
                    Qt::Tool |
                #endif
                    Qt::FramelessWindowHint |
                    Qt::WindowSystemMenuHint |
                    Qt::NoDropShadowWindowHint |
                    Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_ShowWithoutActivating);    
}

CustomStyleWidget::~CustomStyleWidget()
{
    delete ui;
}
