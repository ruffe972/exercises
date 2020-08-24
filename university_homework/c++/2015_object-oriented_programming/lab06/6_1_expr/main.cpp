#include <iostream>
#include <fstream>
#include "expression.h"
#include "operand_node_test.h"
#include "operator_node_test.h"
#include "expression_test.h"
#include "standard.h"


int main()
{
    OperandNodeTest operandNodeTest;
    OperatorNodeTest operatorNodeTest;
    ExpressionTest expressionTest;
    if (QTest::qExec(&operandNodeTest) || QTest::qExec(&operatorNodeTest)
            || QTest::qExec(&expressionTest))
    {
        class TestsNotPassed {};
        throw TestsNotPassed();
    }

    std::cout << "\nThe file must be correct, unary operators are not supported."
              << "\nEnter the expression input file name: ";
    std::ifstream input(readFileName());
    Expression expression;
    expression.read(input);
    expression.print();
    std::cout << "= " << expression.calculate() << '\n';
    return 0;
}
