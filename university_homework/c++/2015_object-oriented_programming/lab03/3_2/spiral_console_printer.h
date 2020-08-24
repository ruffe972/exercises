#pragma once
#include "spiral_printer.h"


//! Matrix spiral console printer
class SpiralConsolePrinter : public SpiralPrinter
{
public:
    //! Print matrix spiral to console
    void print(const Matrix<int> &matrix) const;
};
