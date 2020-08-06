TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ershovString.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    ershovString.h

