#include <iostream>
#include <fstream>
#include <climits>
#include "standard.h"
using std::cout;
using std::endl;


enum State
{
    //numeration is for states.txt, errorState must be equal to 0
    errorState,
    emptyState = 1,
    mantissaSign = 2,
    dotAndNoDigitsInMantissa = 3,
    dotWithDigitsInMantissa = 4,
    emptyExponent = 5,
    exponentSign = 6,
    digitsInExponent = 7,
    digitsAndNoDotInMantissa = 8,
    statesNumber
};


const int charactersAmount = CHAR_MAX + 1;
const int inputEnd = 0;


void scanStateTable(const char *fileName, int nextStates[][charactersAmount], bool *stateIsCorrect)
{
    std::ifstream file;
    file.open(fileName);
    while (file.get() != '\n')
    {
        file.unget();
        int stateFrom = 0;
        file >> stateFrom;
        int stateTo = 0;
        file >> stateTo;        
        file.get();
        char character = file.get();
        switch (character)
        {
        case '+':
        case 'e':
            //+|- or e|E
            nextStates[stateFrom][character] = stateTo;
            if (character == '+')
                character = '-';
            else
                character = 'E';
            nextStates[stateFrom][character] = stateTo;
            break;
        case '.':
            nextStates[stateFrom]['.'] = stateTo;
            break;
        case '\\':
            //digit
            for (int i = '0'; i <= '9'; i++)
                nextStates[stateFrom][i] = stateTo;
            break;
        }
        while (character != '\n')
            character = file.get();
    }

    int state = 0;
    file.get();
    while (file >> state)
    {
        stateIsCorrect[state] = true;
        file.get();
    }
    file.close();
}


int main()
{        
    cout << "Input format: (float\\n)*" << endl;
    cout << "Enter the file name with a float number: ";
    char *name = scanFileName("input.txt");
    std::ifstream inputFile;
    inputFile.open(name);
    delete[] name;    
    int nextStates[statesNumber][charactersAmount] = {};
    bool stateIsCorrect[statesNumber] = {};
    scanStateTable("states.txt", nextStates, stateIsCorrect);

    while (inputFile.peek() != EOF)
    {
        int cursorPosition = 0;
        int state = emptyState;
        char character = inputFile.get();
        while (character != '\n' && state != errorState)
        {
            cout << character;
            state = nextStates[state][character];
            character = inputFile.get();
            cursorPosition++;
        }
        cout << endl;
        if (stateIsCorrect[state])
            cout << "Correct";
        else if (state == errorState)
        {
            inputFile.unget();
            inputFile.unget();
            //Сharacter numeration starts from 1
            cout << "Error on character #" << cursorPosition;
            cout << ": '" << (char)inputFile.get() << "'";
            inputFile.get();
        }
        else
            cout << "Incorrect";
        cout << endl << endl;
    }

    inputFile.close();
    return 0;
}
