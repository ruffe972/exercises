#include <iostream>
#include <fstream>
#include <climits>
#include "floatMachine.h"
using std::cout;
using std::endl;


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
