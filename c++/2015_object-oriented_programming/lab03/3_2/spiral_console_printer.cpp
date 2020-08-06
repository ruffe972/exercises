#include <iostream>
#include "spiral_console_printer.h"


void SpiralConsolePrinter::print(const Matrix<int> &matrix) const
{
    purePrint(matrix, std::cout);
}
