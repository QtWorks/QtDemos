#ifndef MACHELPER_H
#define MACHELPER_H

#include <list>
#include <map>
#include <QPair>
#include <QList>
#include <QPixmap>

QPixmap GetAllWindows(std::list<long> &windows);
void GetAllWindows(QList<QPair<long, QRect>> &windows);
QRect GetWindowGeometry(long window_id);

void MoveWidgetOnTop(QWidget *pwgt);
void MoveWidgetOrderBack(QWidget *pwgt);

void MoveWidgetBehind(QWidget *pwgt, long target_window_id);

QPixmap grabWindow(WId window, int x, int y, int width, int height, bool isRetinaMain,  int devicescale);
#endif // MACHELPER_H
