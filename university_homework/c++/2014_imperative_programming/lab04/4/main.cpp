#include <stdio.h>
#include "calculator.h"
#include "textOperations.h"


int main()
{
    printf("Enter an expression:\n");
    char string[maxStringLen];
    scanString(string, maxStringLen);
    printf("= %f\n", calculate(string));
}
