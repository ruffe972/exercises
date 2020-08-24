#include "tic_tac_toe.h"
#include "tic_tac_toe_core_test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TicTacToeCoreTest test;
    if (QTest::qExec(&test))
        return -1;
    TicTacToe window;
    window.show();
    return app.exec();
}
