#-------------------------------------------------
#
# Project created by QtCreator 2015-03-26T22:49:04
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4_3
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    main_window.cpp \
    two_operands_calculator.cpp

HEADERS  += \
    main_window.h \
    two_operands_calculator.h \
    two_operands_calculator_test.h

FORMS    += \
