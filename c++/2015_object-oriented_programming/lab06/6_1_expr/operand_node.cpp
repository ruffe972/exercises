#include <iostream>
#include "operand_node.h"


void OperandNode::read(std::istream &input)
{
    input >> value;
    input.get();
}


double OperandNode::calculate() const
{
    return value;
}


void OperandNode::print() const
{
    std::cout << value << ' ';
}
