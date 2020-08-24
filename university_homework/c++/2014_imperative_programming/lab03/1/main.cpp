#include <stdio.h>
#include "circularList.h"


int main()
{
    printf("Enter n & m, n = the amount of soldiers, m = step: ");
    int soldiersNumber = 0;
    int step = 0;
    scanf("%d %d", &soldiersNumber, &step);
    solveCounting(soldiersNumber, step);
}
