#include <iostream>
#include "expression.h"
#include "operand_node.h"
#include "operator_node.h"


void Expression::read(std::istream &input)
{
    read(root, input);
}


void Expression::print() const
{
    if (!root)
    {
        throw EmptyExpressionError();
    }
    root->print();
}


double Expression::calculate() const
{
    if (!root)
    {
        throw EmptyExpressionError();
    }
    return root->calculate();
}


void Expression::read(std::unique_ptr<ExpressionNode> &node, std::istream &input)
{
    if (input.peek() == '(')
    {
        node.reset(new OperatorNode);
    }
    else
    {
        node.reset(new OperandNode);
    }
    node->read(input);
}
