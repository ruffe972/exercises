#include <iostream>
#include <fstream>
#include "standard.h"
#include "matrix.h"
#include "matrix_test.h"
#include "spiral_console_printer.h"
#include "spiral_file_printer.h"
#include "spiral_file_printer_test.h"


int main()
{
    MatrixTest testMatrix;
    SpiralFilePrinterTest testPrinter;
    if (QTest::qExec(&testMatrix) != 0 || QTest::qExec(&testPrinter) != 0)
        return -1;
    using std::cout;
    cout << "\nEnter the input file name containing\nthe matrix length and the matrix itself:\n";
    auto inputFileName = readFileName("input.txt");
    std::ifstream input(inputFileName);
    delete inputFileName;
    int matrixLen = 0;
    input >> matrixLen;
    Matrix<int> matrix(matrixLen, matrixLen);
    matrix.read(input);
    input.close();
    enum Command
    {
        doNothingCommand,
        consoleCommand,
        fileCommand
    };
    cout << consoleCommand << " - console output, " << fileCommand << " - file output.\n";
    cout << "Enter the command: ";
    int command = doNothingCommand;
    SpiralPrinter *spiralPrinter = nullptr;
    while (command != consoleCommand && command != fileCommand)
    {
        std::cin >> command;
        if (command == consoleCommand)
            spiralPrinter = new SpiralConsolePrinter;
        else if (command == fileCommand)
            spiralPrinter = new SpiralFilePrinter;
    }
    spiralPrinter->print(matrix);
    delete spiralPrinter;
    cout << '\n';
    return 0;
}

