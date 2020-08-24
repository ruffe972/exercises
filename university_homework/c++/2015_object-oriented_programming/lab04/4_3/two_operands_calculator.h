#pragma once
#include <QVector>

/// Single operation calculator
class TwoOperandsCalculator
{
public:
    class DivisionByZero {};
    enum class Operation { plus = '+', minus = '-', multiply = '*', divide = '/' };
    static double calculate(double left, TwoOperandsCalculator::Operation, double right);
    static const QVector<Operation> operations;
};
