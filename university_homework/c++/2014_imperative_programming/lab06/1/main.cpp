#include <iostream>
#include <cstring>
#include <cctype>
#include "set.h"
using namespace std;


int toDigit(char symbol)
{
    return symbol - '0';
}


enum Command
{
    exitCommand,
    elementExistsCommand,
    addElementCommand,
    removeElementCommand,
    printAscendingCommand,
    printDescendingCommand,
    printDebugCommand,
    printHelpCommand
};

const int maxInputLength = 100;


void printHelp()
{
    cout << exitCommand            << " - exit" << endl;
    cout << elementExistsCommand   << " - check if an element is in the set" << endl;
    cout << addElementCommand      << " - add an element to the set" << endl;
    cout << removeElementCommand   << " - remove an element from the set" << endl;
    cout << printAscendingCommand  << " - print out set elemets in ascending order" << endl;
    cout << printDescendingCommand << " - print out set elemets in descending order" << endl;
    cout << printDebugCommand      << " - print out set elemets for debug" << endl;
    cout << "Any other command shows these instructions.";
}


int main()
{
    Set *set = createSet();
    int command = printHelpCommand;
    while (command != exitCommand)
    {
        switch (command)
        {
        case elementExistsCommand:
        {
            int element = 0;
            cin >> element;
            if (elementExists(element, set))
                cout << "The set contains this element.";
            else
                cout << "The set doesn't contain this element.";
            break;
        }
        case addElementCommand:
        {
            int element = 0;
            cin >> element;
            addElement(element, set);
            cout << "The element has been added to the set.";
            break;
        }
        case removeElementCommand:
        {
            int element = 0;
            cin >> element;
            removeElement(element, set);
            cout << "The element has been removed from the set.";
            break;
        }
        case printAscendingCommand:
            printAscending(set);
            break;
        case printDescendingCommand:
            printDescending(set);
            break;
        case printDebugCommand:
            printDebug(set);
            break;
        default:
            printHelp();
            break;
        }
        cout << endl << endl;
        char input[maxInputLength];
        cin >> input;
        if (strlen(input) == 1 && isdigit(input[0]))
            command = toDigit(input[0]);
        else
            command = printHelpCommand;
    }    
    deleteSet(set);
    return 0;
}
