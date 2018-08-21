#include "borderwidgetex.h"
#include "ui_borderwidgetex.h"
#include <QMouseEvent>
#include <QPainter>
#include <QCursor>
#include <QDebug>
#include <QBitmap>
#include <QPalette>
#include "machelper.h"

BorderWidgetEx::BorderWidgetEx(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorderWidgetEx)
{
    ui->setupUi(this);

    QWidget::setWindowFlags(Qt::FramelessWindowHint);
    QWidget::setAttribute(Qt::WA_TranslucentBackground, true);
    QWidget::setAttribute(Qt::WA_MacShowFocusRect, false);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setFocusPolicy(Qt::NoFocus);

    connect(&m_timer, &QTimer::timeout, this, &BorderWidgetEx::updateBorder);
    m_timer.setSingleShot(false);
    m_timer.setInterval(500);
}

BorderWidgetEx::~BorderWidgetEx()
{
    delete ui;
}

void BorderWidgetEx::setTargetWindowID(long id)
{
    m_window_id = id;
}

void BorderWidgetEx::startBorderCheck()
{
    m_timer.start();
}

void BorderWidgetEx::updateBorder()
{
    QRect rc = GetWindowGeometry(m_window_id);

    if (m_rect != rc) {
        qDebug() << "new target geom " << rc;
        m_rect = rc;
        rc.adjust(-10, -10, 10, 50);
        setGeometry(rc);

        show();
//        MoveWidgetOrderBack(this);
        MoveWidgetBehind(this, m_window_id);
    }
}
