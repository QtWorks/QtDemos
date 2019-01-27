#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtAV>
//#include <QtAVWidgets>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QVideoWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHBoxLayout *playout = new QHBoxLayout(ui->centralWidget);

//    QtAV::GLWidgetRenderer2 *renderer = new QtAV::GLWidgetRenderer2(ui->centralWidget);
//    playout->addWidget(renderer);
//    QtAV::AVPlayer *player = new QtAV::AVPlayer(this);
//    player->setRenderer(renderer);
//    player->play("https://www.joywok.com/api2/file/download?id=MA7Cw5q2y3SoqwDa&access_token=Z9SxQU8ZJ1TrMLIQ");

    QVideoWidget *videoWidget = new QVideoWidget(ui->centralWidget);
    QMediaPlayer* player = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    playout->addWidget(videoWidget);
    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl("https://www.joywok.com/api2/file/download?id=2Dpi5OQcCT847nbr&access_token=vELTUanlg1SpEl8d"));
    player->setVolume(80);
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
