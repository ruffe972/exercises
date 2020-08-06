#pragma once
#include "expression_node.h"


/// Expression tree operand node (with no children, obviously)
class OperandNode : public ExpressionNode
{
public:
    OperandNode() : value(0) {}
    void read(std::istream &);
    double calculate() const;
    void print() const;
private:
    int value;
};
