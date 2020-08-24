#include <iostream>
#include <fstream>
#include <climits>
#include <cctype>
#include "standard.h"
#include "floatMachine.h"
using std::cout;
using std::endl;


bool isPlusOrMinus(char ch)
{
    return ch == '+' || ch == '-';
}


bool isBinaryOperator(char ch)
{
    return isPlusOrMinus(ch) || ch == '*' || ch == '/';
}


// Passing these arrays as function arguments is.. nasty..
int nextStates[statesNumber][charactersAmount] = {};
bool stateIsCorrect[statesNumber] = {};


bool readUnsignedFloatNumber(std::ifstream &input, int &errorPosition)
{
    int state = emptyState;
    int previousState = emptyState;
    while (state != errorState)
    {
        previousState = state;
        state = nextStates[state][input.get()];
        errorPosition++;
    }
    input.unget();
    errorPosition--;
    return stateIsCorrect[previousState];
}


bool readFloatExpression(std::ifstream &input, int &errorPosition);


bool readUnaryOperationOrNumber(std::ifstream &input, int &errorPosition)
{
    char ch = input.get();
    errorPosition++;
    if (ch == '(')
    {
        bool success = readFloatExpression(input, errorPosition);
        if (success && input.peek() == ')')
        {
            input.get();
            errorPosition++;
            return true;
        }
        return false;
    }
    else if (isPlusOrMinus(ch))
        return readFloatExpression(input, errorPosition);
    else if (isdigit(ch) || ch == '.')
    {
        input.unget();
        errorPosition--;
        return readUnsignedFloatNumber(input, errorPosition);
    }
    errorPosition--;
    return false;
}


bool readBinaryOperation(std::ifstream &input, int &errorPosition)
{
    // Немного не соответствует введённой грамматике, по ней эта функция должна всегда
    // возвращать true, ибо одно из порождений В - пустая строка, её всегда можно породить.    
    if (isBinaryOperator(input.peek()))
    {
        input.get();
        errorPosition++;
        return readFloatExpression(input, errorPosition);
    }
    return true;
}


bool readFloatExpression(std::ifstream &input, int &errorPosition)
{
    return readUnaryOperationOrNumber(input, errorPosition) && readBinaryOperation(input, errorPosition);
}


int main()
{
    // F -> UB
    // U -> (F) | [+-]F | id
    // B -> [/+-*]F | e
    // Legend: F - FloatExpression, U - UnaryOperationOrNumber, B - BinaryOperation.

    cout << "Parsing is Python-like (no ++ and -- operators)." << endl;
    cout << "Input format: no whitespace except for \\n in the end." << endl;
    cout << "Enter a file name containing an expression: ";
    std::ifstream input;
    char *name = scanFileName("input.txt");
    input.open(name);
    delete[] name;
    scanStateTable("states.txt", nextStates, stateIsCorrect);
    int errorPosition = 1;
    if (readFloatExpression(input, errorPosition) && input.peek() == '\n')
        cout << "It's correct ^^";
    else
        cout << "It's incorrect, error position: " << errorPosition;
    cout << endl;
    return 0;
}
