#include <stdio.h>

int main()
{
    printf("Enter x: ");
    float x = 0;
    scanf("%f", &x);
    float sqrX = x * x;
    printf("x ^ 4 + x ^ 3 + x ^ 2 + x = %f", (sqrX + x) * (sqrX + 1));
}
