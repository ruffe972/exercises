#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>

int main()
{
    //Думаю, случаи с разными знаками необязательно рассматривать.
    printf("Enter positive integers a & n: ");
    int number = 0;
    int power = 0;
    scanf("%d %d", &number, &power);
    printf("%d ^ %d = ", number, power);
    int result = 1;
    while (power != 0)
    {
        if (power % 2 == 0)
        {
            number *= number;
            power /= 2;
        }
        else
        {
            result *= number;
            power -= 1;
        }
    }
    printf("%d", result);
}    