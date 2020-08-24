QT       += core
QT       += testlib

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    hashtable.cpp \
    hashfunctions.cpp

HEADERS += \
    hashtable.h \
    hashtabletest.h \
    hashfunctions.h
