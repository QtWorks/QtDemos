#ifndef IRREGUALARWIDGET_H
#define IRREGUALARWIDGET_H

#include <QWidget>

class IrregualarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IrregualarWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *ev) override;
};

void AllwaysOnTop(QWidget *pwgt);

#endif // IRREGUALARWIDGET_H
