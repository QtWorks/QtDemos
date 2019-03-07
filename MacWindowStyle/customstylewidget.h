#ifndef CUSTOMSTYLEWIDGET_H
#define CUSTOMSTYLEWIDGET_H

#include <QWidget>

namespace Ui {
class CustomStyleWidget;
}

class CustomStyleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomStyleWidget(QWidget *parent = 0);
    ~CustomStyleWidget();

private:
    Ui::CustomStyleWidget *ui;
};

void MoveWidgetOnTop(QWidget *pwgt);

#endif // CUSTOMSTYLEWIDGET_H
