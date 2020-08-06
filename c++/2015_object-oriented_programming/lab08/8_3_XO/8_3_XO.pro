#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T21:38:45
#
#-------------------------------------------------

QT       += core testlib gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 8_3_XO
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++1y

SOURCES += main.cpp \
    tic_tac_toe.cpp \
    tic_tac_toe_core.cpp

HEADERS  += \
    tic_tac_toe.h \
    tic_tac_toe_core.h \
    tic_tac_toe_core_test.h
