#pragma once
#include <QString>
#include <QVector>

class TicTacToeCore
{
private:
    enum class Diagonal { major, anti };
    TicTacToeCore(int cellsInLine);
    QString readDiagonal(Diagonal type, int row, int column) const;
    bool playerWon(int newTurnRow, int newTurnColumn) const;
    friend class TicTacToeCoreTest;
    friend class TicTacToe;
    QVector<QChar> symbols;
    QVector<QVector<QChar>> fieldMatrix;
    QVector<QString> victoryStrings;
    int victoryLineLength;
    int currentPlayer;
};
