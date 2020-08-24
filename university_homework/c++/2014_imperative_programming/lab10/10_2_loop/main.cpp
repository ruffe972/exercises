#include <iostream>
#include <fstream>
#include <climits>
#include "standard.h"
#include "floatMachine.h"
using std::cout;
using std::endl;


void printLineAndGoToBeginning(std::ifstream &file)
{
    char ch = file.get();
    while (ch != '\n')
    {
        cout << ch;
        ch = file.get();
    }
    cout << endl;
    file.seekg(0);
}


bool readUnsignedFloatNumber(std::ifstream &input, int nextStates[][charactersAmount], bool *stateIsCorrect)
{
    //int cursorPosition = 0;
    int state = emptyState;
    int previousState = emptyState;
    while (state != errorState)
    {
        previousState = state;
        state = nextStates[state][input.get()];
        //cursorPosition++;
    }
    input.unget();
    return stateIsCorrect[previousState];
}


bool isUnaryOperator(char ch)
{
    return ch == '+' || ch == '-';
}


bool isBinaryOperator(char ch)
{
    return isUnaryOperator(ch) || ch == '*' || ch == '/';
}


void skipSpaces(std::ifstream &input)
{
    while (input.get() == ' ');
    input.unget();
}


int main()
{
    // F -> UB
    // U -> [+-]U | id
    // B -> [+-*/]UB | e

    cout << "Parsing is Python-like (no ++ and -- operators)." << endl;
    cout << "Expression format: line\\n" << endl;
    cout << "Enter a file name containing an expression: ";
    std::ifstream input;
    char *name = scanFileName("input.txt");
    input.open(name);
    delete[] name;
    int nextStates[statesNumber][charactersAmount] = {};
    bool stateIsCorrect[statesNumber] = {};
    scanStateTable("states.txt", nextStates, stateIsCorrect);
    printLineAndGoToBeginning(input);

    bool valid = true;
    char ch = '*';
    while (valid && ch != '\n')
    {
        ch = input.get();
        while (isUnaryOperator(ch) || ch == ' ')
            ch = input.get();
        input.unget();

        valid = readUnsignedFloatNumber(input, nextStates, stateIsCorrect);
        skipSpaces(input);
        ch = input.get();
        if (!isBinaryOperator(ch) && ch != '\n')
            valid = false;
        else
            skipSpaces(input);
    }

    if (valid)
        cout << "Correct";
    else
        cout << "Incorrect";
    input.close();
    cout << endl;
    return 0;
}
