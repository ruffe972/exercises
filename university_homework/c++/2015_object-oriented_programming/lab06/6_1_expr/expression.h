#pragma once
#include <memory>
#include "expression_node.h"
#include "operator_node.h"


/// Expression node wrapper
class Expression : public ExpressionNode
{
public:
    /// Thrown if trying to do something with an empty expression
    class EmptyExpressionError {};
    void read(std::istream &);
    void print() const;
    double calculate() const;
private:
    friend class OperatorNode;
    static void read(std::unique_ptr<ExpressionNode> &, std::istream &);
    std::unique_ptr<ExpressionNode> root;
};
