#pragma once
#include <iostream>


/// Represents objects that have properties of a node in an expression tree
class ExpressionNode
{
public:
    /// Read a node and all its children
    virtual void read(std::istream &) = 0;
    /// Calculate the node subtree
    virtual double calculate() const = 0;
    /// Print the node subtree
    virtual void print() const = 0;
};
