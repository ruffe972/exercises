#pragma once
#include "spiral_printer.h"


//! Matrix spiral file printer
class SpiralFilePrinter : public SpiralPrinter
{
public:
    //! Print matrix spiral to file
    void print(const Matrix<int> &matrix) const;
    static constexpr const char *defaultFileName = "output.txt";
};
