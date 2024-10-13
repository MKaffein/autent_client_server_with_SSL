#include <QApplication>
#include "ssl_client.h"
#include "ssl_server.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SslServer server;
    server.show();

    SslClient client;
    client.show();

    return app.exec();
}
