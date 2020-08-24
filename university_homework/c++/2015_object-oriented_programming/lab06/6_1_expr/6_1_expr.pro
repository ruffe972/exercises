#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T13:34:28
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++1y

SOURCES += main.cpp \
    operand_node.cpp \
    operator_node.cpp \
    expression.cpp \
    standard.cpp

HEADERS += \
    expression_node.h \
    operand_node.h \
    operator_node.h \
    expression.h \
    operand_node_test.h \
    operator_node_test.h \
    expression_test.h \
    standard.h
