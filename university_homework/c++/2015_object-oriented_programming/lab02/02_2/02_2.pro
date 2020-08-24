QT       += core
QT       += testlib

TEMPLATE = app
TARGET = main.cpp
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    standard.cpp

HEADERS += \
    stack.h \
    standard.h \
    array_stack.h \
    linked_stack.h \
    array_stack_test.h \
    linked_stack_test.h

