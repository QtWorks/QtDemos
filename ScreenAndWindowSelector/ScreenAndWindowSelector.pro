#-------------------------------------------------
#
# Project created by QtCreator 2018-08-13T16:10:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets macextras

TARGET = ScreenAndWindowSelector
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -framework CoreFoundation -framework Carbon -framework AppKit -lobjc

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    machelper.mm \
    windowselector.cpp \
    widgetborder.cpp \
    borderwidgetex.cpp

HEADERS += \
        mainwindow.h \
    machelper.h \
    windowselector.h \
    widgetborder.h \
    borderwidgetex.h

FORMS += \
        mainwindow.ui \
    borderwidgetex.ui
