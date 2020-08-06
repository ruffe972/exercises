TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ershovString.cpp \
    standard.cpp \
    hash.cpp \
    stringList.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    ershovString.h \
    standard.h \
    hash.h \
    stringList.h

