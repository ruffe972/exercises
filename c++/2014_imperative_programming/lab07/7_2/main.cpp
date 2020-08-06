#include <iostream>
#include "ershovString.h"
using std::cin;
using std::cout;
using std::endl;


int main()
{
    String *string = createString();
    cout << "Enter a string (not a line): ";
    scan(cin, string);
    char *cStyleString = cString(string);
    cout << endl << "Converted to C string:" << endl << cStyleString;
    delete[] cStyleString;

    cout << "\n\n" << "Substring - symbols 3-5:" << endl;
    String *string2 = substring(string, 3, 6);
    print(string2);
    deleteString(string2);
    string2 = clone(string);
    cout << "\n\n" << "Clone:" << endl;
    print(string2);
    deleteString(string2);
    string2 = concatenate(string, string);
    cout << "\n\n" << "Doubled:" << endl;
    print(string2);
    deleteString(string2);


    cout << "\n\n" << "String length: " << len(string);
    cout << "\n\n" << "Enter a second string:" << endl;
    string2 = createString();
    scan(cin, string2);
    cout << "These strings are ";
    if (!areEqual(string, string2))
        cout << "not ";
    cout << "equal.";
    deleteString(string2);

    deleteString(string);
    cout << "\n\n";
    return 0;
}
