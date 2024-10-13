#include "ssl_server.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QSslConfiguration>

SslServer::SslServer(QWidget *parent) : QWidget(parent), server(new QTcpServer(this)), startButton(new QPushButton("Start Server", this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(startButton);
    setLayout(layout);

    connect(startButton, &QPushButton::clicked, this, &SslServer::startServer);
    connect(server, &QTcpServer::newConnection, this, &SslServer::onNewConnection);

    setWindowTitle("SSL Server");
    resize(300, 200);
}

void SslServer::startServer()
{
    QSslConfiguration sslConfig;
    // Укажите путь к вашему сертификату и ключу
    // sslConfig.setPrivateKey("path/to/key.pem");
    // sslConfig.setCertificate("path/to/certificate.pem");
    // server->setSslConfiguration(sslConfig);

    if (server->listen(QHostAddress::Any, 12345)) {
        qDebug() << "Server started.";
    } else {
        qDebug() << "Server failed to start:" << server->errorString();
    }
}

void SslServer::onNewConnection()
{
    clientSocket = new QSslSocket(this);
    clientSocket->setSocketDescriptor(server->nextPendingConnection()->socketDescriptor());
    connect(clientSocket, &QSslSocket::readyRead, this, &SslServer::onReadyRead);

    qDebug() << "New client connected.";
}

void SslServer::onReadyRead()
{
    qDebug() << "Server received data:" << clientSocket->readAll();
}
