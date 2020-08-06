#pragma once
#include "expression_node.h"
#include "expression.h"


/// Expression tree operator node
class OperatorNode : public ExpressionNode
{
public:
    /// Thrown if trying to do something with no child
    class NoOperandError {};
    void read(std::istream &);
    double calculate() const;
    void print() const;
private:
    class InvalidOperator {};
    char currentOperator;
    std::unique_ptr<ExpressionNode> leftChild;
    std::unique_ptr<ExpressionNode> rightChild;
};
