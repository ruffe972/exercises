QT += core
QT += testlib

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    spiral_console_printer.cpp \
    spiral_file_printer.cpp \
    spiral_printer.cpp \
    standard.cpp

HEADERS += \
    matrix.h \
    spiral_console_printer.h \
    spiral_file_printer.h \
    spiral_printer.h \
    standard.h \
    matrix_test.h \
    spiral_file_printer_test.h

