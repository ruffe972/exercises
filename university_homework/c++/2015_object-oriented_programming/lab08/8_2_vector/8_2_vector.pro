QT       += core
QT       += testlib
QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++1y

HEADERS += \
    vector.h \
    vector_test.h
