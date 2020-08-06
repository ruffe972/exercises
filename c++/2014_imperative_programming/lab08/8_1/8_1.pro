TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    graph.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    list.h \
    graph.h

