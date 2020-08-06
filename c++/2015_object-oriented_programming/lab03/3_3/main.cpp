#include <iostream>
#include "standard.h"
#include "sorted_set.h"
#include "sorted_set_test.h"
#include "singly_linked_list.h"
using std::cin;
using std::cout;


int main()
{
    SortedSetTest setTest;
    if (QTest::qExec(&setTest) != 0)
        return -1;
    cout << "\nInput format:\n'add 1 2 3\\n' - add list = [1, 2, 3] to the set;\n";
    cout << "'remove 1 2\\n' - remove list, equal (by length) to list = [1, 2] from the set;\n";
    cout << "'print\\n' - print set;\n'length\\n' - print set length.\n";
    cout << "Excess whitespace is not allowed!\n\n";
    cout << "Enter the input file name: ";
    auto fileName = readFileName("input.txt");
    std::ifstream input(fileName);
    delete fileName;
    SortedSet set;
    enum Command
    {
        addList = 'a',
        removeList = 'r',
        printSet = 'p',
        printSetLen = 'l'
    };
    char symbol = '0';
    while (input.get(symbol))
    {        
        while(isalpha(input.get()));
        input.unget();
        switch (symbol)
        {
        case addList:
            set.add(new SinglyLinkedList<int>(input));
            break;
        case removeList:
        {
            auto auxiliaryList = new SinglyLinkedList<int>(input);
            set.remove(auxiliaryList);
            delete auxiliaryList;
            break;
        }
        case printSet:
            set.print();
            break;
        case printSetLen:
            cout << "length(set) = " << set.len() << "\n\n";
            break;
        }
        input.get();
    }
    input.close();
    return 0;
}

