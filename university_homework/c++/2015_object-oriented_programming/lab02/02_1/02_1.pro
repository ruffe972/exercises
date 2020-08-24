QT       += core
QT       += testlib

TEMPLATE = app
TARGET = 02_1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp

HEADERS += \
    list.h \
    singly_linked_list.h \
    doubly_linked_list.h \
    singly_linked_list_test.h \
    doubly_linked_list_test.h

