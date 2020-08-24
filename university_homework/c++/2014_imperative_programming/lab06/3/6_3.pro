TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    set.cpp \
    standard.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    set.h \
    standard.h

