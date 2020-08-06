#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T13:20:09
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quotes
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++1y

SOURCES += main.cpp\
        quoteswindow.cpp

HEADERS  += quoteswindow.h

FORMS    += quoteswindow.ui
