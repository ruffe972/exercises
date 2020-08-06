#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "matrix.h"
#include "spiral_file_printer.h"
#include "standard.h"


class SpiralFilePrinterTest : public QObject
{
    Q_OBJECT
public:
    explicit SpiralFilePrinterTest(QObject *parent = 0) : QObject(parent) {}
private:
    SpiralFilePrinter *printer;
private slots:

    void init()
    {
        printer = new SpiralFilePrinter;
    }


    void cellTest()
    {
        Matrix<int> matrix(1, 1);
        matrix(0, 0) = 6;
        printer->print(matrix);
        QVERIFY(fileIsEqualToString(SpiralFilePrinter::defaultFileName, "Spiral path:\n6 "));
    }


    void normalTest()
    {
        Matrix<int> matrix(3, 3);
        matrix(0, 0) = 1;
        matrix(0, 1) = 2;
        matrix(0, 2) = 3;
        matrix(1, 0) = 4;
        matrix(1, 1) = 5;
        matrix(1, 2) = 6;
        matrix(2, 0) = 7;
        matrix(2, 1) = 8;
        matrix(2, 2) = 9;
        auto correctResult = "Spiral path:\n5 6 9 8 7 4 1 2 3 ";
        printer->print(matrix);
        QVERIFY(fileIsEqualToString(SpiralFilePrinter::defaultFileName, correctResult));
    }


    void cleanup()
    {
        delete printer;
    }
};
