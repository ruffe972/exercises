TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    standard.cpp \
    floatMachine.cpp \

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    standard.h \
    floatMachine.h \
