#include "application.h"
#include <QEvent>
#include <QDebug>

Application::Application(int &argc, char **argv, int)
    : QApplication(argc, argv)
{

}

bool Application::event(QEvent *ev)
{
    qDebug() << "event " << ev->type();
    return QApplication::event(ev);
}
