#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPixmap GenerateTrayIcon(int num);

public slots:
    void updateTimerOut();

private:
    Ui::MainWindow *ui;
    QTimer m_timer;
    class QSystemTrayIcon *m_ti;
};

#endif // MAINWINDOW_H
