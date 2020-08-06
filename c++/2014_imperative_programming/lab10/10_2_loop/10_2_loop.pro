TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    floatMachine.cpp \
    standard.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    floatMachine.h \
    standard.h

