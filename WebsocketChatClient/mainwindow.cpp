#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_socket) {
        m_socket->close();
        m_socket->deleteLater();
    }
}

void MainWindow::connectToServer(QUrl url)
{
    if (!m_socket) {
        m_socket = new QWebSocket;
        connect(m_socket, &QWebSocket::textMessageReceived, this, &MainWindow::onMessageReceived);
        connect(m_socket, &QWebSocket::disconnected, this, &MainWindow::close);
    }
    m_socket->open(url);
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    text = QString("{\"id\": \"desktop\", \"body\":\"%1\"}").arg(text);
    ui->lineEdit->clear();

    m_socket->sendTextMessage(text);
}

void MainWindow::onMessageReceived(const QString &message)
{
    QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
    QJsonObject obj = doc.object();
    QString text = obj.value("body").toString();
    ui->plainTextEdit->appendPlainText(text);
}
