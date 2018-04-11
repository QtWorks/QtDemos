#ifndef MYSCROLLAREA_H
#define MYSCROLLAREA_H

#include <QWidget>
#include <QList>

class TextBrowserItem;
class MyScrollArea : public QWidget
{
    Q_OBJECT
public:
    explicit MyScrollArea(QWidget *pwgt = nullptr);

    void addItem(TextBrowserItem *item) { m_itemlist.append(item); }

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

private:
    bool m_pressed = false;
    QList<TextBrowserItem*> m_itemlist;
    QPoint m_startpos;
};

#endif // MYSCROLLAREA_H
