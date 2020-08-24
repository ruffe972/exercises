#include <stdio.h>
#include <stdlib.h>


int sign(int x)
{
    return (x > 0) - (x < 0);
}    


int main()
{
    // 7/3=2(1), 7/-3=-2(1), -7/3=-3(2), -7/-3=3(2)
    printf("Enter the integers a and b (b != 0): ");
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int modulo = abs(a);
    int quotient = 0;
    while (modulo >= abs(b))
    {
        modulo -= abs(b);
        ++quotient;
    }
    if (modulo != 0 && a < 0)
    {
        //modulo = abs(b) - modulo;
        quotient++;
    }    
    printf("a div b = %d", quotient * sign(a) * sign(b));
}