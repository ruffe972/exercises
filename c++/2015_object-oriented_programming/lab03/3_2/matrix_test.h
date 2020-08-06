#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "matrix.h"


class MatrixTest : public QObject
{
    Q_OBJECT
public:
    explicit MatrixTest(QObject *parent = 0) : QObject(parent) {}
private slots:

    void cellTest()
    {
        Matrix<int> matrix(1, 1);
        QCOMPARE(1, matrix.width());
        QCOMPARE(1, matrix.height());
        QCOMPARE(0, matrix(0, 0));
        matrix(0, 0) = 5;
        QCOMPARE(5, matrix(0, 0));
    }


    void simpleTest()
    {
        Matrix<char> matrix(3, 2);
        QCOMPARE(3, matrix.width());
        QCOMPARE(2, matrix.height());
        matrix(0, 0) = 'a';
        matrix(0, 1) = 'b';
        matrix(0, 2) = 'c';
        matrix(1, 0) = 'd';
        matrix(1, 1) = 'e';
        matrix(1, 2) = 'f';
        using std::swap;
        swap(matrix(0, 0), matrix(1, 0));
        QVERIFY(matrix(0, 0) == 'd' && matrix(1, 0) == 'a');
    }


    void stressTest()
    {
        const int superLen = 1000;
        Matrix<int> matrix(superLen - 1, superLen + 1);
        for (int i = 0; i < matrix.height(); i++)
            for (int j = 0; j < matrix.width(); j++)
                matrix(i, j) = i + j;
        QCOMPARE(matrix(matrix.height() - 1, matrix.width() - 1), 2 * (superLen - 1));
    }
};
