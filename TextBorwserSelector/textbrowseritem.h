#ifndef TEXTBROWSERITEM_H
#define TEXTBROWSERITEM_H

#include <QTextBrowser>

class TextBrowserItem : public QTextBrowser
{
    Q_OBJECT
public:
    TextBrowserItem(QWidget *pwgt = nullptr);

    void selectByPos(const QPoint& from, const QPoint& to);

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
};

#endif // TEXTBROWSERITEM_H
