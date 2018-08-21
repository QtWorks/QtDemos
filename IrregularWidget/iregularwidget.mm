#include "irregualarwidget.h"
#import <AppKit/AppKit.h>
#import <Carbon/Carbon.h>

void AllwaysOnTop(QWidget *pwgt)
{
    NSWindow* window2 = [(id)(pwgt->winId()) window];
    window2.level = NSPopUpMenuWindowLevel;
}
