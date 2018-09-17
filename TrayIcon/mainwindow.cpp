#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>
#include <QIcon>
#include <QPixmap>
#include <QFontMetrics>
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ti = new QSystemTrayIcon(this);

    QPixmap pix(60, 44);
    pix.fill(Qt::red);
    QIcon icon(pix);
    m_ti->setIcon(icon);
    m_ti->show();

    connect(&m_timer, &QTimer::timeout, this, &MainWindow::updateTimerOut);
    m_timer.setInterval(1000);
    m_timer.setSingleShot(false);
    m_timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPixmap MainWindow::GenerateTrayIcon(int num)
{
    QString text = num > 99 ? "99+" : QString::number(num);

    QFont ft;
    ft.setPixelSize(20);
    QPixmap pix(60, 44);
    pix.fill(Qt::transparent);

    QPainter pt(&pix);
    pt.setFont(ft);
    QPixmap icon("/Users/lixiaoning/Program/desktopclient/src/joywok_qt/Resources/skin/logomac.png");
    pt.drawPixmap(QRect(0, 0, 44, 44), icon);
    pt.setPen(QColor("#22334A"));
    pt.drawText(QRect(44, 0, 16, 44), Qt::AlignCenter, text);

    pt.end();
    return pix;
}

void MainWindow::updateTimerOut()
{
    int num = qrand() % 120;
//    int num = 108;
    QPixmap pix = GenerateTrayIcon(num);
    qDebug() << "generate pix size " << pix;
    m_ti->setIcon(QIcon());
    m_ti->setIcon(QIcon(pix));

//    static int sz = 44;
//    ++sz;
//    qDebug() << "pix width " << sz;
//    QPixmap pix(sz, 44);
//    pix.fill(Qt::red);
//    m_ti->setIcon(QIcon(pix));
}
