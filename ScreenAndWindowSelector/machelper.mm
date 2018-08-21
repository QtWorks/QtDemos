#include "machelper.h"
#import <AppKit/AppKit.h>
#import <Carbon/Carbon.h>
#include <objc/objc.h>
#include <objc/message.h>
#include <QtMac>
#include <QWidget>


QPixmap GetAllWindows(std::list<long> &windows)
{
    CFArrayRef windowList = CGWindowListCopyWindowInfo (kCGWindowListOptionOnScreenOnly, kCGNullWindowID);
    NSInteger creatorid;
    CGRect creatorbounds;
    for (NSMutableDictionary* entry in (NSArray*)windowList)
    {
        NSString* ownerName = [entry objectForKey:(id)kCGWindowOwnerName];
        NSInteger ownerOnScreen = [[entry objectForKey:(id)kCGWindowIsOnscreen] integerValue];
        NSInteger ownerLayer = [[entry objectForKey:(id)kCGWindowLayer] integerValue];
        NSInteger ownerPID = [[entry objectForKey:(id)kCGWindowOwnerPID] integerValue];
        NSInteger ownerNumber = [[entry objectForKey:(id)kCGWindowNumber] integerValue];
        CGRect bounds;
        CGRectMakeWithDictionaryRepresentation((CFDictionaryRef)entry[(id)kCGWindowBounds], &bounds);
        NSLog(@"%@:%d:%d:%d:%d:  %.0f/%.0f  %.0f/%.0f", ownerName, ownerPID, ownerNumber, ownerOnScreen, ownerLayer, bounds.origin.x, bounds.origin.y, bounds.size.width, bounds.size.height);
        windows.push_back((long)ownerPID);

        if ([ownerName isEqualToString: @"Sublime Text"]) {
            creatorid = ownerNumber;
            creatorbounds = bounds;
        }
    }

//    CFArrayRef windowsRef = CGWindowListCreate(kCGWindowListOptionOnScreenOnly, kCGNullWindowID);
//    NSRect rect = [[NSScreen mainScreen] frame];
//    CGImageRef imgRef = CGWindowListCreateImageFromArray(rect, windowsRef, kCGWindowImageDefault);
//    CFRelease(windowsRef);
//    QPixmap image = QtMac::fromCGImageRef(imgRef);
//    CGImageRelease(imgRef);
//    return image;



    // 屏幕截图
    CGImageRef imgRef = CGWindowListCreateImage(creatorbounds, kCGWindowListOptionIncludingWindow, (CGWindowID)creatorid, kCGWindowImageDefault);
    QPixmap image = QtMac::fromCGImageRef(imgRef);
    CGImageRelease(imgRef);
    return image;
}

void GetAllWindows(QList<QPair<long, QRect>> &windows)
{
    CFArrayRef windowList = CGWindowListCopyWindowInfo (kCGWindowListOptionOnScreenAboveWindow, kCGNullWindowID);
    for (NSMutableDictionary* entry in (NSArray*)windowList)
    {
        NSString* ownerName = [entry objectForKey:(id)kCGWindowOwnerName];
        NSInteger ownerOnScreen = [[entry objectForKey:(id)kCGWindowIsOnscreen] integerValue];
        NSInteger ownerLayer = [[entry objectForKey:(id)kCGWindowLayer] integerValue];
        NSInteger ownerPID = [[entry objectForKey:(id)kCGWindowOwnerPID] integerValue];
        NSInteger ownerNumber = [[entry objectForKey:(id)kCGWindowNumber] integerValue];
        CGRect bounds;
        CGRectMakeWithDictionaryRepresentation((CFDictionaryRef)entry[(id)kCGWindowBounds], &bounds);
        NSLog(@"%@:%d:%d:%d:%d:  %.0f/%.0f  %.0f/%.0f", ownerName, ownerPID, ownerNumber, ownerOnScreen, ownerLayer, bounds.origin.x, bounds.origin.y, bounds.size.width, bounds.size.height);

        if (ownerLayer >= 0) {
            QPair<long, QRect> window((long)ownerNumber, QRect(bounds.origin.x, bounds.origin.y, bounds.size.width, bounds.size.height));
            windows.append(window);
        }
    }
    CFRelease(windowList);
}

void MoveWidgetOnTop(QWidget *pwgt)
{
    NSWindow* window2 = [(id)(pwgt->winId()) window];
    window2.level = NSPopUpMenuWindowLevel;
}

QPixmap grabWindow(WId window, int x, int y, int width, int height, bool isRetinaMain, int devicescale)
{
    // TODO window should be handled
    Q_UNUSED(window)

    const int maxDisplays = 128; // 128 displays should be enough for everyone.
    CGDirectDisplayID displays[maxDisplays];
    CGDisplayCount displayCount;
    CGRect cgRect;

    if (width < 0 || height < 0) {
        // get all displays
        cgRect = CGRectInfinite;
    } else {
        cgRect = CGRectMake(x, y, width, height);
    }
    const CGDisplayErr err = CGGetDisplaysWithRect(cgRect, maxDisplays, displays, &displayCount);

    if (err && displayCount == 0)
        return QPixmap();

    // calculate pixmap size
    QSize windowSize(width, height);
    if (width < 0 || height < 0) {
        QRect windowRect;
        for (uint i = 0; i < displayCount; ++i) {
            const CGRect cgRect = CGDisplayBounds(displays[i]);
            QRect qRect(cgRect.origin.x, cgRect.origin.y, cgRect.size.width, cgRect.size.height);
            windowRect = windowRect.united(qRect);
        }
        if (width < 0)
            windowSize.setWidth(windowRect.width());
        if (height < 0)
            windowSize.setHeight(windowRect.height());
    }

    QPixmap windowPixmap(windowSize * devicescale);
    windowPixmap.fill(Qt::transparent);

    for (uint i = 0; i < displayCount; ++i) {
        const CGRect bounds = CGDisplayBounds(displays[i]);
        QRect displayRect;

        //根据主屏幕是否是Retina屏来计算副屏幕的位置
        if (isRetinaMain) {
            int w = (width < 0 ? bounds.size.width : width);
            int h = (height < 0 ? bounds.size.height : height);
            displayRect = QRect(x, y, w, h);

            if (devicescale == 1)
                displayRect = QRect(0, 0, w, h);
        } else {
            int w = (width < 0 ? bounds.size.width : width) * devicescale;
            int h = (height < 0 ? bounds.size.height : height) * devicescale;
            displayRect = QRect(x, y, w, h);

            if (devicescale > 1)
                displayRect = QRect(x > 0 ? 0 : x, y > 0 ? 0 : y, w, h);
        }

        CGImageRef image = CGDisplayCreateImageForRect(displays[i],
                                                       CGRectMake(displayRect.x(), displayRect.y(), displayRect.width(), displayRect.height()));
        windowPixmap = QtMac::fromCGImageRef(image);
    }
    return windowPixmap;

}

QRect GetWindowGeometry(long window_id)
{
    QRect rc;
    CFArrayRef windowList = CGWindowListCopyWindowInfo (kCGWindowListOptionOnScreenAboveWindow, kCGNullWindowID);
    for (NSMutableDictionary* entry in (NSArray*)windowList)
    {
        NSInteger ownerNumber = [[entry objectForKey:(id)kCGWindowNumber] integerValue];
        if ((long)ownerNumber == window_id) {
            CGRect bounds;
            CGRectMakeWithDictionaryRepresentation((CFDictionaryRef)entry[(id)kCGWindowBounds], &bounds);
            rc = QRect(bounds.origin.x, bounds.origin.y, bounds.size.width, bounds.size.height);
            return rc;
        }
    }
    CFRelease(windowList);
    return rc;
}

void MoveWidgetOrderBack(QWidget *pwgt)
{
    NSWindow* window2 = [(id)(pwgt->winId()) window];
    [window2 orderBack];
}

void MoveWidgetBehind(QWidget *pwgt, long target_window_id)
{
    NSWindow* window2 = [(id)(pwgt->winId()) window];
    [window2 orderWindow:NSWindowBelow relativeTo:(NSInteger)target_window_id];
}
