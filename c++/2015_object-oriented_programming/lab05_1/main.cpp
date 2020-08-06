#include <iostream>
#include <string>
#include "hashtable.h"
#include "hashtabletest.h"


int main()
{
    HashTableTest test;
    if (QTest::qExec(&test))
        return -1;

    using std::cout;
    cout << "\nChoose a hash function.\n";
    cout << "'sum' - sum of characters, any other input - polynomial:\n";
    using std::cin;
    using std::string;
    string commandString;
    std::getline(cin, commandString);
    HashTable *hashTable = nullptr;
    if (commandString == "sum")
        hashTable = new HashTable(sumHash);
    else
        hashTable = new HashTable;

    cout << "Commands:\nadd string\nfind string\nremove string\nstat\nexit\n\n";
    while (commandString != "exit")
    {
        std::getline(cin, commandString);
        if (commandString == "stat")
            hashTable->showStatistics();
        else
        {
            string argument;
            if (commandString.find(" ") != string::npos)
            {
                argument = commandString.substr(commandString.find(" ") + 1);
                commandString = commandString.substr(0, commandString.find(" "));
            }
            string message;
            if (commandString == "add")
            {
                hashTable->add(argument);
                message = "added";
            }
            else if (commandString == "find")
                message = (hashTable->find(argument) ? "" : "not ") + string("found");
            else if (commandString == "remove")
            {
                hashTable->remove(argument);
                message = "removed";
            }
            if (message != "")
                cout << "The string \"" << argument << "\" was " << message << ".\n";
        }
    }

    delete hashTable;
    return 0;
}
