TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    textOperations.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    textOperations.h

