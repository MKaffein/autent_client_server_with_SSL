# Название проекта
TARGET = ssl_server
TEMPLATE = app

# Исходные файлы
SOURCES += ssl_server.cpp \
            mainwindow.cpp

# Заголовочные файлы (не обязательно)
HEADERS += mainwindow.h

# Ресурсы (если есть)
# RESOURCES += resources.qrc

# Прочие настройки
QT += core gui network
CONFIG += c++11
LIBS += -L/usr/lib/x86_64-linux-gnu -lssl -lcrypto
