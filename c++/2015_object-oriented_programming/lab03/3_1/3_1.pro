QT       += core
QT       += testlib


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    standard.cpp

HEADERS += \
    sorter.h \
    quick_sorter.h \
    standard.h \
    insertion_sorter.h \
    insertion_sorter_test.h \
    quick_sorter_test.h

