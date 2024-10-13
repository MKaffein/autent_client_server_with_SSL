#ifndef SSL_SERVER_H
#define SSL_SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QSslSocket>

class QPushButton;

class SslServer : public QWidget
{
    Q_OBJECT

public:
    explicit SslServer(QWidget *parent = nullptr);

private slots:
    void onNewConnection();
    void onReadyRead();
    void startServer();

private:
    QTcpServer *server;
    QSslSocket *clientSocket;
    QPushButton *startButton;
};

#endif // SSL_SERVER_H
