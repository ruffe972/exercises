#include <iostream>
#include "expression.h"
#include "operator_node.h"


void OperatorNode::read(std::istream &input)
{
    input.get(); //(
    input.get(currentOperator);
    input.get(); //space
    Expression::read(leftChild, input);
    Expression::read(rightChild, input);
    input.get(); //)
}


double OperatorNode::calculate() const
{
    if (!leftChild || !rightChild)
    {
        throw NoOperandError();
    }
    double left = leftChild->calculate();
    double right = rightChild->calculate();
    switch (currentOperator)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    }
    throw InvalidOperator();
}


void OperatorNode::print() const
{
    if (!leftChild || !rightChild)
    {
        throw NoOperandError();
    }
    std::cout << '(';
    leftChild->print();
    std::cout << currentOperator << ' ';
    rightChild->print();
    std::cout << ") ";
}
