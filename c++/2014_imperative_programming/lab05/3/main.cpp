#include <stdio.h>


const char nullChar = '0';


void test()
{
    //NOT FOLLOWING STYLE GUIDE HERE FOR BETTER TESTING.
    char ch = '\''; ch = '"'; //ivan ch = '\"';
    "'''''\'\"\";\n";
    /* \*/
    int i = 0;
    /*
     * //abc
    //\
    It is a not supported multi-line comment (this and a previous line).
    */
    i = 1;
    /*/*///
    // /* */
}


void getSymbol(char& symbol, char& previousSymbol, FILE* file)
{
    previousSymbol = symbol;
    symbol = fgetc(file);
}


void checkForEscapeCharacter(char& symbol, FILE* file)
{
    if (symbol == '\\')
        fgetc(file);
}


int main()
{
    printf("Multi-line comments //...\\<\\n>... are not supported. Required comments:\n\n");
    test();
    FILE* inputFile = fopen("main.cpp", "r");
    char symbol = nullChar;
    char previousSymbol = nullChar;

    while (!feof(inputFile))
    {
        getSymbol(symbol, previousSymbol, inputFile);
        if (previousSymbol == '/' && symbol == '*')
        {
            symbol = fgetc(inputFile);
            while (previousSymbol != '*' || symbol != '/')
                getSymbol(symbol, previousSymbol, inputFile);
            // previousSymbol will be equivalent to nullChar
            // at the next iteration of the biggest while loop.
            // It is necessary because /**/// is 2 empty comments.
            symbol = nullChar;
        }
        else if (previousSymbol == '/' && symbol == '/')
        {
            printf("//");
            while (!feof(inputFile) && symbol != '\n')
            {
                symbol = fgetc(inputFile);
                printf("%c", symbol);
            }
        }
        else if (symbol == '\'')
        {
            symbol = fgetc(inputFile);
            checkForEscapeCharacter(symbol, inputFile);
            fgetc(inputFile);
        }
        else if (symbol == '"')
        {
            symbol = fgetc(inputFile);
            while (symbol != '"')
            {
                checkForEscapeCharacter(symbol, inputFile);
                symbol = fgetc(inputFile);
            }
        }
    }

    printf("\n");
    fclose(inputFile);
}
