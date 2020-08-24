TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    matrixGraph.cpp \
    standard.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    list.h \
    matrixGraph.h \
    standard.h

