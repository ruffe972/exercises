#include "two_operands_calculator.h"


double TwoOperandsCalculator::calculate(double left, Operation operation, double right)
{
    switch (operation)
    {
    case Operation::plus:
        return left + right;
    case Operation::minus:
        return left - right;
    case Operation::multiply:
        return left * right;
    case Operation::divide:
        if (right == 0)
            throw DivisionByZero();
        return left / right;
    }
    return 0;
}


const QVector<TwoOperandsCalculator::Operation> TwoOperandsCalculator::operations =
    { Operation::plus, Operation::minus, Operation::multiply, Operation::divide };
