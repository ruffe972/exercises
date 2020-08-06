#include "tic_tac_toe_core.h"

TicTacToeCore::TicTacToeCore(int cellsInLine) :
    symbols({'X', 'O'}),
    victoryLineLength(cellsInLine < 3 ? cellsInLine : (cellsInLine < 7 ? 3 : 5))
{
    for (auto symbol: symbols)
        victoryStrings << QString(victoryLineLength, symbol);
    for (int i = 0; i < cellsInLine; i++)
        fieldMatrix << QVector<QChar>(cellsInLine);
}

QString TicTacToeCore::readDiagonal(Diagonal type, int row, int col) const
{
    auto isValid = [this](int index) { return index >= 0 && index < fieldMatrix.size(); };
    int shift = type == Diagonal::major ? 1 : -1;
    while (isValid(row) && isValid(col))
    {
        row--;
        col -= shift;
    }
    row++;
    col += shift;
    QString string;
    while (isValid(row) && isValid(col))
    {
        string.append(fieldMatrix[row][col]);
        row++;
        col += shift;
    }
    return string;
}

bool TicTacToeCore::playerWon(int newTurnRow, int newTurnColumn) const
{
    QVector<QString> lines(2);
    for (int col = 0; col < fieldMatrix.size(); col++)
        lines[0].append(fieldMatrix[newTurnRow][col]);
    for (int row = 0; row < fieldMatrix.size(); row++)
        lines[1].append(fieldMatrix[row][newTurnColumn]);
    lines << readDiagonal(Diagonal::major, newTurnRow, newTurnColumn);
    lines << readDiagonal(Diagonal::anti, newTurnRow, newTurnColumn);
    int i = 0;
    while (i < lines.size() && lines[i].indexOf(victoryStrings[currentPlayer]) == -1)
        i++;
    return i != lines.size();
}
