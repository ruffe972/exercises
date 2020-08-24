#include <iostream>
#include <fstream>
#include <cctype>
#include "standard.h"
#include "linked_stack.h"
#include "array_stack.h"
#include "array_stack_test.h"
#include "linked_stack_test.h"
using std::cout;
using std::ws;


//! @returns calculated expression
//! @param input - input file
double calculateFromPostfix(std::istream &input)
{
    Stack<double> *stack = new LinkedStack<double>;
    input >> ws;
    char ch = '0';
    while (input.get(ch))
    {
        if (isdigit(ch))
        {
            input.unget();
            double number = 0;
            input >> number;
            stack->push(number);
        }
        else
        {
            double rightOperand = stack->pop();
            double leftOperand = stack->pop();
            switch (ch)
            {
            case '+':
                stack->push(leftOperand + rightOperand);
                break;
            case '-':
                stack->push(leftOperand - rightOperand);
                break;
            case '*':
                stack->push(leftOperand * rightOperand);
                break;
            case '/':
                stack->push(leftOperand / rightOperand);
                break;
            }
        }
        input >> ws;
    }
    double result = stack->pop();
    delete stack;
    return result;
}


int main()
{
    ArrayStackTest arrayStack;
    LinkedStackTest linkedStack;
    if (QTest::qExec(&arrayStack) * QTest::qExec(&linkedStack) == 0)
    {
        cout << "\nEnter the file name containg a correct expression in postfix notation\n";
        cout << "(unary +, - and extra symbols except ' ' are not allowed):\n";
        char *fileName = readFileName("input.txt");
        std::ifstream input(fileName);
        delete fileName;
        cout << "result = " << calculateFromPostfix(input) << '\n';
        input.close();
    }
    return 0;
}

