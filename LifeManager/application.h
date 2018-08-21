#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class Application : public QApplication
{
public:
    Application(int &argc, char **argv, int = ApplicationFlags);

protected:
    bool event(QEvent *ev) override;
};

#endif // APPLICATION_H
