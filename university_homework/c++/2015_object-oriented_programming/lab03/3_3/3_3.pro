QT += core
QT += testlib

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    standard.cpp \
    sorted_set.cpp \
    i_comparable.cpp

HEADERS += \
    list.h \
    singly_linked_list.h \
    standard.h \
    sorted_set.h \
    i_comparable.h \
    sorted_set_test.h

