#include "widgetborder.h"
#include <QMouseEvent>
#include <QPainter>
#include <QCursor>
#include <QDebug>
#include <QBitmap>
#include <QPalette>
#include "machelper.h"
#include "borderwidgetex.h"


WidgetSelector::WidgetSelector(QWidget *parent)
    : QLabel(parent)
{
#ifdef Q_OS_MAC
    Qt::WindowFlags windowFlags = Qt::Tool |
            Qt::WindowStaysOnTopHint |
            Qt::FramelessWindowHint |
            Qt::CustomizeWindowHint;
    setWindowFlags(windowFlags);
#else
    setWindowFlags(Qt::WindowStaysOnTopHint);  //使窗口置顶
    showFullScreen();
#endif

    setMouseTracking(true);

    connect(&m_timer, &QTimer::timeout, this, &WidgetSelector::checkWindowList);
    m_timer.setSingleShot(false);
    m_timer.setInterval(500);
}

void WidgetSelector::initPixmap(const QPixmap &pix, const QList<QPair<long, QRect> > &windows)
{
    m_pix = pix;
    setPixmap(pix);
    m_windowlist = windows;

    for (auto window : m_windowlist) {
        qDebug() << "window rect " << window;
    }

    QLabel *label = new QLabel(this);
    QPixmap px = QPixmap(size());
    px.fill(QColor(25,25,25,127));  //用蓝色填充这个pixmap  且透明度为127 (255表示不透明)
    label->resize(size());
    label->setPixmap(px);
    label->show();

    m_timer.start();
}

void WidgetSelector::stopWindowCheck()
{
    m_timer.stop();
    close();
}

void WidgetSelector::mouseMoveEvent(QMouseEvent *ev)
{
    QLabel::mouseMoveEvent(ev);
}

void WidgetSelector::checkWindowList()
{
    qDebug() << "checkWindowList" << geometry() << QCursor::pos();
    if (!geometry().contains(QCursor::pos())) {
        if (m_selected) {
            m_selected->hide();
            m_currentid = 0;
        }
        return;
    }

    //找到包含鼠标的窗口
    for (auto window : m_windowlist) {
        if (window.second.contains(QCursor::pos())) {
            qDebug() << "window funded " << window.first << window.second;
            if (m_currentid == window.first) {
                return;
            } else {
                m_currentid = window.first;
                QRect rc(window.second.x() - geometry().x(), window.second.y() - geometry().y(),
                         window.second.width(), window.second.height());
                updateAutoPix(rc);
                return;
            }
        }
    }
}

void WidgetSelector::onWindowSelected()
{
    emit windowSelected();

    stopWindowCheck();

    //创建外包的窗口
    BorderWidgetEx *border = new BorderWidgetEx();
    border->setTargetWindowID(m_currentid);
    border->startBorderCheck();
}

void WidgetSelector::updateAutoPix(QRect autoRect)
{
    int devicerate = m_pix.devicePixelRatio();
    int x = autoRect.x() * devicerate;
    int y = autoRect.y() * devicerate;
    int borderWidth = 2; //边框的宽度
    int width = autoRect.width() * devicerate;
    int height= autoRect.height() * devicerate;
    QPixmap autoPix = m_pix.copy(x,y,width,height);
    autoPix.setDevicePixelRatio(devicerate);
    QSize totalSize = QSize((autoRect.width() + borderWidth*2)*devicerate,(autoRect.height() + borderWidth *2)*devicerate);
    QPixmap pix  = QPixmap(totalSize);
    pix.fill(Qt::yellow);
    QPainter painter(&pix);
//    QRect rcOrign(borderWidth * devicerate, borderWidth *devicerate, autoPix.width() * devicerate, autoPix.height() * devicerate);
//    painter.drawPixmap(rcOrign, autoPix);
    QRect rcOrign(borderWidth* devicerate, borderWidth* devicerate, autoPix.width(), autoPix.height());
    painter.drawPixmap(rcOrign, autoPix);
    pix.setDevicePixelRatio(devicerate);


    if (!m_selected){
        m_selected = new ClickLabel(this);
        connect(m_selected, &ClickLabel::clicked, this, &WidgetSelector::onWindowSelected);
    }

    m_selected->setPixmap(pix);
    m_selected->setGeometry(autoRect.adjusted(-borderWidth, -borderWidth, borderWidth, borderWidth));
    m_selected->show();
}

ClickLabel::ClickLabel(QWidget *parent)
    : QLabel(parent)
{
}

void ClickLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QLabel::mouseReleaseEvent(ev);
    emit clicked();
}

MessageBride::MessageBride(QObject *parent)
    : QObject(parent)
{
}

WidgetBorder::WidgetBorder(QWidget *parent)
    : QWidget(parent)
{
    QWidget::setWindowFlags(Qt::FramelessWindowHint);
//    QWidget::setAttribute(Qt::WA_TranslucentBackground, true);
    QWidget::setAttribute(Qt::WA_MacShowFocusRect, false);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setFocusPolicy(Qt::NoFocus);

    connect(&m_timer, &QTimer::timeout, this, &WidgetBorder::updateBorder);
    m_timer.setInterval(500);
    m_timer.setSingleShot(false);
}

void WidgetBorder::setTargetWindowID(long id)
{
    m_window_id = id;
}

void WidgetBorder::startBorderCheck()
{
    m_timer.start();
}


void WidgetBorder::updateBorder()
{
    QRect rc = GetWindowGeometry(m_window_id);

    if (m_rect != rc) {
        qDebug() << "new target geom " << rc;
        m_rect = rc;
        rc.adjust(-10, -10, 10, 10);
        setGeometry(rc);

        QPixmap pix(rc.size());
        pix.fill(Qt::transparent);
        QPainter pt(&pix);
        QPen pen;
        pen.setWidth(10);
        pen.setColor(Qt::black);
        pt.setPen(pen);
        pt.drawRect(5, 5, rc.width()-10, rc.height()-10);
//        pt.fillRect(QRect(0, 0, rc.width(), rc.height()), QBrush(Qt::red));
        setMask(pix.mask());

//        QPalette pal = palette();
//        pal.setBrush(QPalette::Background, QBrush(Qt::red));
//        setPalette(pal);


        show();
//        MoveWidgetOrderBack(this);
        MoveWidgetBehind(this, m_window_id);
    }
}

//void WidgetBorder::mousePressEvent(QMouseEvent *ev)
//{
//    ev->accept();
//}

//void WidgetBorder::mouseMoveEvent(QMouseEvent *ev)
//{
//    ev->accept();
//}

//void WidgetBorder::mouseReleaseEvent(QMouseEvent *ev)
//{
//    ev->accept();
//}
