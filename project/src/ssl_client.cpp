#include "ssl_client.h"
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHostAddress>
#include <QSslConfiguration>
#include <QDebug>

SslClient::SslClient(QWidget *parent) : QWidget(parent), socket(new QSslSocket(this)),
    connectButton(new QPushButton("Connect", this)),
    hostLineEdit(new QLineEdit(this)), portLineEdit(new QLineEdit(this)),
    logTextEdit(new QTextEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *connectLayout = new QHBoxLayout;
    connectLayout->addWidget(hostLineEdit);
    connectLayout->addWidget(portLineEdit);
    connectLayout->addWidget(connectButton);

    mainLayout->addLayout(connectLayout);
    mainLayout->addWidget(logTextEdit);

    setLayout(mainLayout);

    connect(connectButton, &QPushButton::clicked, this, &SslClient::connectToServer);
    connect(socket, &QSslSocket::readyRead, this, &SslClient::onReadyRead);

    setWindowTitle("SSL Client");
    resize(400, 300);
}

void SslClient::connectToServer()
{
    QSslConfiguration sslConfig;
    // Укажите путь к вашему сертификату и ключу
    // sslConfig.setPrivateKey("path/to/key.pem");
    // sslConfig.setCertificate("path/to/certificate.pem");
    // socket->setSslConfiguration(sslConfig);

    socket->connectToHost(QHostAddress(hostLineEdit->text()), portLineEdit->text().toUInt());

    if (socket->waitForConnected(3000)) {
        logTextEdit->append("Connected to server.");
    } else {
        logTextEdit->append("Failed to connect: " + socket->errorString());
    }
}

void SslClient::onReadyRead()
{
    logTextEdit->append("Received: " + socket->readAll());
}
