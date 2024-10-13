TEMPLATE = app
CONFIG += c++11 widget
CONFIG -= app_bundle
CONFIG += link_pkgconfig
PKGCONFIG += Qt5Network Qt5Core Qt5Gui Qt5Widgets

SOURCES += src/main.cpp \
           src/ssl_client.cpp \
           src/ssl_server.cpp

HEADERS += src/ssl_client.h \
           src/ssl_server.h

INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5
LIBS += -lssl -lcrypto
