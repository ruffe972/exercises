#include <iostream>
#include "ershovString.h"
using std::cin;
using std::cout;
using std::endl;


hashType hashPower(int power)
{
    hashType base = hashBase;
    hashType result = 1;
    while (power != 0)
        if (power % 2 == 0)
        {
            base *= base;
            power /= 2;
        }
        else
        {
            result *= base;
            power -= 1;
        }
    return result;
}


int main()
{
    String *string = createString();
    cout << "Enter a string:" << endl;
    scanLine(cin, string);
    cout << "Enter a pattern:" << endl;
    String *pattern = createString();
    scanLine(cin, pattern);

    hashType highestPower = hashPower(len(pattern) - 1);
    hashType patternHash = hash(pattern);
    String *window = substring(string, 0, len(pattern) - 1);
    hashType windowHash = hash(window);
    deleteString(window);

    cout << "All start indeces of pattern occurences:" << endl;
    for (int i = 0; i <= len(string) - len(pattern); i++)
    {
        char previousChar = '\0';
        if (i != 0)
            previousChar = charAt(string, i - 1);
        windowHash = (windowHash - previousChar * highestPower) * hashBase;
        windowHash += charAt(string, i + len(pattern) - 1);
        if (windowHash == patternHash)
        {
            window = substring(string, i, i + len(pattern));
            if (areEqual(pattern, window))
                cout << i << ' ';
            deleteString(window);
        }
    }
    deleteString(string);
    deleteString(pattern);

    cout << endl;
    return 0;
}
