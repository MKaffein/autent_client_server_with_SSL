#ifndef SSL_CLIENT_H
#define SSL_CLIENT_H

#include <QWidget>
#include <QSslSocket>

class QPushButton;
class QLineEdit;
class QTextEdit;

class SslClient : public QWidget
{
    Q_OBJECT

public:
    explicit SslClient(QWidget *parent = nullptr);

private slots:
    void connectToServer();
    void onReadyRead();

private:
    QSslSocket *socket;
    QPushButton *connectButton;
    QLineEdit *hostLineEdit;
    QLineEdit *portLineEdit;
    QTextEdit *logTextEdit;
};

#endif // SSL_CLIENT_H
