#-------------------------------------------------
#
# Project created by QtCreator 2014-03-26T13:11:55
#
#-------------------------------------------------

QT       += core gui network

TARGET = KServer
TEMPLATE = app


SOURCES += main.cpp \
    ethernet.cpp \
    portcfg.cpp

HEADERS  += \
    ethernet.h \
    portcfg.h \
    paquete.h

FORMS    += \
    ethernet.ui \
    portcfg.ui

include(qextserialport/qextserialport.pri)

