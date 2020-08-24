#include <QApplication>
#include "main_window.h"
#include "two_operands_calculator_test.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TwoOperandsCalculatorTest test;
    if (QTest::qExec(&test))
        return -1;
    MainWindow window;
    window.show();
    return app.exec();
}
