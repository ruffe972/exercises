#-------------------------------------------------
#
# Project created by QtCreator 2015-09-28T20:06:12
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = lab11.exe
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++1y

SOURCES += main.cpp \
    network.cpp \
    computer.cpp \
    inputoutput.cpp \
    windowscomputer.cpp \
    linuxcomputer.cpp \
    computercreator.cpp

HEADERS += \
    network.h \
    computer.h \
    inputoutput.h \
    networktest.h \
    linuxcomputer.h \
    windowscomputer.h \
    computercreator.h

DISTFILES += \
    input.txt
