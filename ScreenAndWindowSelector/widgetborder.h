#ifndef WIDGETBORDER_H
#define WIDGETBORDER_H

#include <QLabel>
#include <QTimer>

class ClickLabel : public QLabel
{
    Q_OBJECT
public:
    ClickLabel(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent *ev) override;
};

class MessageBride : public QObject
{
    Q_OBJECT
public:
    MessageBride(QObject *parent = nullptr);

signals:
    void finish();
};

class WidgetSelector : public QLabel
{
    Q_OBJECT
public:
    WidgetSelector(QWidget *parent = nullptr);

    void initPixmap(const QPixmap &pix, const QList<QPair<long, QRect>> &windows);

public slots:
    void stopWindowCheck();

signals:
    void windowSelected();

protected:
    void mouseMoveEvent(QMouseEvent *ev) override;

private slots:
    void checkWindowList();
    void onWindowSelected();

private:
    void updateAutoPix(QRect autoRect);

    QList<QPair<long, QRect> > m_windowlist;
    QPixmap m_pix;
    ClickLabel *m_selected = nullptr;
    long m_currentid;
    QTimer m_timer;
};

class WidgetBorder : public QWidget
{
    Q_OBJECT
public:
    WidgetBorder(QWidget* parent = nullptr);
    void setTargetWindowID(long id);
    void startBorderCheck();

public slots:
    void updateBorder();

protected:
//    void mousePressEvent(QMouseEvent *ev) override;
//    void mouseMoveEvent(QMouseEvent *ev) override;
//    void mouseReleaseEvent(QMouseEvent *ev) override;

private:
    long m_window_id;

    QTimer m_timer;
    QRect m_rect;
};


#endif // WIDGETBORDER_H
