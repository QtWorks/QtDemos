#ifndef BORDERWIDGETEX_H
#define BORDERWIDGETEX_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class BorderWidgetEx;
}

class BorderWidgetEx : public QWidget
{
    Q_OBJECT

public:
    explicit BorderWidgetEx(QWidget *parent = 0);
    ~BorderWidgetEx();

    void setTargetWindowID(long id);
    void startBorderCheck();

public slots:
    void updateBorder();


private:
    long m_window_id;

    QTimer m_timer;
    QRect m_rect;

private:
    Ui::BorderWidgetEx *ui;
};

#endif // BORDERWIDGETEX_H
