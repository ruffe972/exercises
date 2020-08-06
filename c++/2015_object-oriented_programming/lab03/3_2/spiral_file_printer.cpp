#include <fstream>
#include "spiral_file_printer.h"


void SpiralFilePrinter::print(const Matrix<int> &matrix) const
{
    std::ofstream output(defaultFileName);
    purePrint(matrix, output);
    output.close();
}
