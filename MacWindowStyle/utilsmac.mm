#import <AppKit/AppKit.h>
#include "customstylewidget.h"
#include <QWidget>

void MoveWidgetOnTop(QWidget *pwgt)
{
    NSWindow *window2 = [(id)(pwgt->winId()) window];
    window2.level = NSPopUpMenuWindowLevel;
}
