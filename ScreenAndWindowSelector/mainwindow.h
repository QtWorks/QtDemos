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

    void setPixmap(const QPixmap &pix);

public slots:
    void checkCursorPosition();

private:
    Ui::MainWindow *ui;
    QTimer m_timer;
};

#endif // MAINWINDOW_H
