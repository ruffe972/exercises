TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    charStack.cpp \
    calculator.cpp \
    textOperations.cpp \
    doubleStack.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    charStack.h \
    calculator.h \
    textOperations.h \
    doubleStack.h

