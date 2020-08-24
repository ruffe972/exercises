#include <iostream>
#include <cstring>
#include <cctype>
#include "set.h"
using std::cin;
using std::cout;
using std::endl;


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
    printHelpCommand,
    skipCommand
};


void printHelp()
{
    cout << exitCommand            << " - exit" << endl;
    cout << elementExistsCommand   << " - check if an element is in the set" << endl;
    cout << addElementCommand      << " - add an element to the set" << endl;
    cout << removeElementCommand   << " - remove an element from the set" << endl;
    cout << printAscendingCommand  << " - print out set elemets in an ascending order" << endl;
    cout << printDescendingCommand << " - print out set elemets in a descending order" << endl;
    cout << printDebugCommand      << " - print out set elemets for a debugging" << endl;
    cout << "Any other int number shows these instructions." << endl;
    cout << "Non-valid input will result in an undefined behaviour.";
}


bool isPrintSetCommand(int command)
{
    switch (command)
    {
    case printAscendingCommand:
    case printDescendingCommand:
    case printDebugCommand:
        return true;
    }
    return false;
}


int main()
{
    Set *set = createSet();
    int command = printHelpCommand;
    while (command != exitCommand)
    {
        if (isPrintSetCommand(command) && isEmpty(set))
        {
            cout << "The set is empty.";
            command = skipCommand;
        }

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
        case skipCommand:
            break;
        default:
            printHelp();
            break;
        }
        cout << "\n\n";
        cin >> command;
    }
    deleteSet(set);
    return 0;
}
