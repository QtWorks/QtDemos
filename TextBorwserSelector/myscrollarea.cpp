#include "myscrollarea.h"
#include <QDebug>
#include <QMouseEvent>
#include "textbrowseritem.h"

MyScrollArea::MyScrollArea(QWidget *pwgt)
    : QWidget(pwgt)
{

}

void MyScrollArea::mousePressEvent(QMouseEvent *ev)
{
    QWidget::mousePressEvent(ev);
    qDebug() << "mouse press " << ev->pos();

    m_pressed = true;
    m_startpos = ev->pos();
}

void MyScrollArea::mouseMoveEvent(QMouseEvent *ev)
{
    QWidget::mouseMoveEvent(ev);
    qDebug() << "mouse move " << ev->pos();

    if (m_pressed) {
        for (TextBrowserItem *item : m_itemlist) {
            item->selectByPos(m_startpos, ev->pos());
        }
    }
}

void MyScrollArea::mouseReleaseEvent(QMouseEvent *ev)
{
    QWidget::mouseReleaseEvent(ev);
    qDebug() << "mouse release " << ev->pos();

    m_pressed = false;
}
