#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "tic_tac_toe_core.h"


class TicTacToeCoreTest : public QObject
{
    Q_OBJECT
public:
    explicit TicTacToeCoreTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void diagonalTest1()
    {
        TicTacToeCore core(1);
        core.fieldMatrix[0][0] = 'O';
        QVERIFY(core.readDiagonal(core.Diagonal::major, 0, 0) == "O");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 0, 0) == "O");
    }

    void diagonalTest2()
    {
        TicTacToeCore core(2);
        core.fieldMatrix.resize(0);
        core.fieldMatrix << QVector<QChar>({'a', 'b'});
        core.fieldMatrix << QVector<QChar>({'c', 'd'});
        QVERIFY(core.readDiagonal(core.Diagonal::major, 0, 0) == "ad");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 0, 1) == "b");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 1, 0) == "c");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 1, 1) == "ad");

        QVERIFY(core.readDiagonal(core.Diagonal::anti, 0, 0) == "a");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 0, 1) == "bc");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 1, 0) == "bc");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 1, 1) == "d");
    }

    void diagonalTest3()
    {
        TicTacToeCore core(3);
        core.fieldMatrix.resize(0);
        core.fieldMatrix << QVector<QChar>({'a', 'b', 'c'});
        core.fieldMatrix << QVector<QChar>({'d', 'e', 'f'});
        core.fieldMatrix << QVector<QChar>({'g', 'h', 'i'});
        QVERIFY(core.readDiagonal(core.Diagonal::major, 0, 0) == "aei");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 0, 1) == "bf");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 0, 2) == "c");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 1, 0) == "dh");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 1, 1) == "aei");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 1, 2) == "bf");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 2, 0) == "g");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 2, 1) == "dh");
        QVERIFY(core.readDiagonal(core.Diagonal::major, 2, 2) == "aei");

        QVERIFY(core.readDiagonal(core.Diagonal::anti, 0, 0) == "a");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 0, 1) == "bd");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 0, 2) == "ceg");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 1, 0) == "bd");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 1, 1) == "ceg");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 1, 2) == "fh");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 2, 0) == "ceg");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 2, 1) == "fh");
        QVERIFY(core.readDiagonal(core.Diagonal::anti, 2, 2) == "i");
    }

    void emptyCellVictoryTest()
    {
        TicTacToeCore core(1);
        core.currentPlayer = 0;
        core.fieldMatrix[0][0] = ' ';
        QVERIFY(!core.playerWon(0, 0));
        core.currentPlayer = 1;
        QVERIFY(!core.playerWon(0, 0));
    }

    void cellVictoryTest()
    {
        TicTacToeCore core(1);
        core.currentPlayer = 0;
        core.fieldMatrix[0][0] = core.symbols[0];
        QVERIFY(core.playerWon(0, 0));
        core.currentPlayer = 1;
        QVERIFY(!core.playerWon(0, 0));
    }

    void finalVictoryTest()
    {
        TicTacToeCore core(4);
        core.fieldMatrix.resize(0);
        core.symbols = {'X', 'O'};
        core.fieldMatrix << QVector<QChar>({'X', 'X', ' ', 'X'});
        core.fieldMatrix << QVector<QChar>({'O', 'X', 'X', 'X'});
        core.fieldMatrix << QVector<QChar>({'O', 'O', ' ', 'X'});
        core.fieldMatrix << QVector<QChar>({'O', 'X', ' ', 'X'});

        core.currentPlayer = 1;
        QVector<QString> victory;
        victory << "----";
        victory << "1---";
        victory << "10--";
        victory << "1---";
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                if (victory[row][col] == '1')
                    QVERIFY(core.playerWon(row, col));
                else if (victory[row][col] == '0')
                    QVERIFY(!core.playerWon(row, col));
            }
        }

        core.currentPlayer = 0;
        victory.resize(0);
        victory << "01-1";
        victory << "-111";
        victory << "---1";
        victory << "-0-1";
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                if (victory[row][col] == '1')
                    QVERIFY(core.playerWon(row, col));
                else if (victory[row][col] == '0')
                    QVERIFY(!core.playerWon(row, col));
            }
        }
    }
};
