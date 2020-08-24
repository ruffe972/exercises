#pragma once
#include <QMainWindow>
#include <QStatusBar>
#include <QGridLayout>
#include <algorithm>
#include "tic_tac_toe_core.h"

/// Click on the non-empty cells several times in a row to start a new game
class TicTacToe : public QMainWindow
{
    Q_OBJECT
public:
    TicTacToe(QWidget *parent = 0);
private slots:
    void buttonClick();
private:
    void setupNewGame();
    int optimalWindowSize(int cellsInLine) const;
    int getOptimalCellsInLine() const;
    /// Field size
    const int desiredCellsNumberInLine = 3;
    const int clicksForNewGame = 5;
    const int statusBarHeight = 20;
    const int approximateMinButtonSize = 30;

    int cellsInLine;
    TicTacToeCore core;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QGridLayout *layout;

    int drawCounter;
    int eraseCounter;
    bool newGameFlag;
};
