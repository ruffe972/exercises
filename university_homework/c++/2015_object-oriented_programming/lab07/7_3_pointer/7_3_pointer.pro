QT       += core
QT       += testlib
QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++1y

SOURCES +=

HEADERS += \
    shared_pointer.h \
    shared_pointer_test.h
