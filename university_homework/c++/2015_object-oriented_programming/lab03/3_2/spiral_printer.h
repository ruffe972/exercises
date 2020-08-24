#pragma once
#include <iostream>
#include "matrix.h"


//! Matrix spiral printer interface
class SpiralPrinter
{
public:
    virtual ~SpiralPrinter() {}
    //! Print matrix spiral
    void virtual print(const Matrix<int> &matrix) const = 0;
protected:
    void purePrint(const Matrix<int> &matrix, std::ostream &output) const;
};
