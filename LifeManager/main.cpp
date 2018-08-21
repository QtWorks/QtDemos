#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include <QSettings>
#include <QDir>
#include "controllerwindow.h"
#include "questioncontainer.h"
#include "application.h"
#include "timechecker.h"

void appAutoRun(bool bAutoRun)
{
    //HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
    QSettings  reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);

    if (bAutoRun)
    {
         QString strAppPath=QDir::toNativeSeparators(QCoreApplication::applicationFilePath());
        //strAppPath.replace(QChar('/'),QChar('\\'),Qt::CaseInsensitive);
        reg.setValue("wirtepad",strAppPath);
    }
    else
    {
        reg.setValue("wirtepad","");
    }

}


int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    appAutoRun(true);

//    ControllerWindow window;
//    window.show();

    QWidget normal;
    normal.show();

    //必须要有一个其他窗口才能将下面的窗口显示处理
    QuestionContainer testwgt;
    testwgt.initQuestionList();
    testwgt.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    testwgt.showFullScreen();

    TimeChecker tm;
    QObject::connect(&tm, &TimeChecker::showQuestions,
                     &testwgt, &QuestionContainer::showQuestions);
    tm.startCheck();
    normal.hide();

    return a.exec();
}
