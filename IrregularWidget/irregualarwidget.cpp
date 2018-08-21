#include "irregualarwidget.h"
#include <QPixmap>
#include <QBitmap>
#include <QLabel>

IrregualarWidget::IrregualarWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(
        #ifdef Q_OS_MAC
            Qt::SubWindow |
        #else
            Qt::Tool |
        #endif
            Qt::FramelessWindowHint |
            Qt::WindowSystemMenuHint |
            Qt::WindowStaysOnTopHint
        );

//    setAttribute(Qt::WA_TransparentForMouseEvents);

//    QPixmap pix(":/iron.png");
//    resize(pix.size());
    //    setMask(pix.mask());

    QLabel *plabel = new QLabel(this);
    plabel->move(0, 0);
    plabel->setText("Hello label");
}

void IrregualarWidget::resizeEvent(QResizeEvent *ev)
{
    QWidget::resizeEvent(ev);

//    QRegion reg(frameGeometry());
//    reg-=QRegion(geometry());
//    reg+=childrenRegion();
//    setMask(reg);
}
