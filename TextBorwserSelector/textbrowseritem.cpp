#include "textbrowseritem.h"
#include <QMouseEvent>
#include <QPoint>
#include <QDebug>

TextBrowserItem::TextBrowserItem(QWidget *pwgt)
    : QTextBrowser(pwgt)
{

}

void TextBrowserItem::selectByPos(const QPoint &from, const QPoint &to)
{
    qDebug() << "select by pos " << from << to;

    QTextCursor cursor = textCursor();
    cursor.clearSelection();
    setTextCursor(cursor);

    if (from.y() == to.y())
        return;

    QPoint lefttop = mapToParent(QPoint(0, 0));
    QPoint rightbottom = mapToParent(QPoint(width(), height()));
    qDebug() << "item pos " << lefttop << rightbottom;

    if (from.y() < to.y() && to.y() > lefttop.y()) {  //从上到下
        qDebug() << "item part select " << cursorForPosition(mapFromParent(from)).position() << cursorForPosition(mapFromParent(to)).position();
        QTextCursor cursorbegin = textCursor();
        cursorbegin.setPosition(cursorForPosition(mapFromParent(from)).position(), QTextCursor::MoveAnchor);
        cursorbegin.setPosition(cursorForPosition(mapFromParent(to)).position(), QTextCursor::KeepAnchor);
        setTextCursor(cursorbegin);
    } else if (from.y() > to.y() && to.y() < rightbottom.y()) { //从下到上
        qDebug() << "item part select " << cursorForPosition(mapFromParent(to)).position() << cursorForPosition(mapFromParent(from)).position();
        QTextCursor cursorbegin = textCursor();
        cursorbegin.setPosition(cursorForPosition(mapFromParent(to)).position(), QTextCursor::MoveAnchor);
        cursorbegin.setPosition(cursorForPosition(mapFromParent(from)).position(), QTextCursor::KeepAnchor);
        setTextCursor(cursorbegin);
    }
}

void TextBrowserItem::mousePressEvent(QMouseEvent *ev)
{
    ev->ignore();
}

void TextBrowserItem::mouseMoveEvent(QMouseEvent *ev)
{
    ev->ignore();
}

void TextBrowserItem::mouseReleaseEvent(QMouseEvent *ev)
{
    ev->ignore();
}
