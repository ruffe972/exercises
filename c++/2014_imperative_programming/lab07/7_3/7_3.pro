TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ershovString.cpp \
    main.cpp \
    hashTable.cpp \
    stringList.cpp \
    standard.cpp

QMAKE_CXXFLAGS += --std=c++11

HEADERS += \
    ershovString.h \
    hashTable.h \
    stringList.h \
    standard.h

