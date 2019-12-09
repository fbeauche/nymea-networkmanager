include(../nymea-networkmanager.pri)

TARGET = nymea-networkmanager

QT += core network bluetooth dbus
QT -= gui

CONFIG += console link_pkgconfig
CONFIG -= app_bundle

TEMPLATE = app
PKGCONFIG += nymea-networkmanager nymea-gpio

HEADERS += \
    application.h \
    core.h \
    loggingcategories.h \
    nymeadservice.h \
    pushbuttonagent.h \
    rasberrypi.h \


SOURCES += \
    main.cpp \
    application.cpp \
    core.cpp \
    loggingcategories.cpp \
    nymeadservice.cpp \
    pushbuttonagent.cpp \
    rasberrypi.cpp \

target.path = /usr/bin
INSTALLS += target
