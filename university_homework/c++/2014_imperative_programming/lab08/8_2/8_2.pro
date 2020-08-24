TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    standard.cpp \
    matrixGraph.cpp \
    list.cpp \
    stack.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    standard.h \
    matrixGraph.h \
    list.h \
    stack.h

