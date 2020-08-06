#include <stdio.h>
typedef unsigned long long ultraInt;


ultraInt power(ultraInt number, int power)
{
    ultraInt returnValue = 1;
    while (power != 0)
    {
        if (power % 2 == 0)
        {
            number *= number;
            power /= 2;
        }
        else
        {
            returnValue *= number;
            power -= 1;
        }
    }    
    return returnValue;
}


ultraInt binaryToDecimal(int binaryNumber[], int numberLength)
{
    ultraInt returnValue = 0;
    for (int i = 0; i < numberLength; i++)
        returnValue = returnValue * 2 + binaryNumber[i];
    return returnValue;
}


ultraInt decimalMantissa(int binaryMantissa[], int mantissaLength)
{
    return binaryToDecimal(binaryMantissa, mantissaLength) * power(5, mantissaLength);
}


ultraInt decimalExponent(int binaryExponent[], const int exponentLength)
{
    return binaryToDecimal(binaryExponent, exponentLength) - (power(2, exponentLength - 1) - 1);
}


int main()
{
    printf("Zeros, subnormals, NaNs and infinities are not supported.\n");
    printf("Mantissa is truncated, not rounded. Enter a number:\n");
    double inputNumber = 0;
    scanf("%lf", &inputNumber);
    unsigned char *inputBytes = (unsigned char*)&inputNumber;
    const int bitsInByte = 8;
    const int bitsInDouble = sizeof(double) * bitsInByte;
    int inputBits[bitsInDouble];
    int inputBitsLength = 0;
    for (int byteNumber = sizeof(double) - 1; byteNumber >= 0; byteNumber--)
    {
        const unsigned char oneAnd7Zeros = 0x80;
        unsigned char bitMask = oneAnd7Zeros;
        for (int i = 0; i < bitsInByte; i++)
        {
            inputBits[inputBitsLength] = (bool)(inputBytes[byteNumber] & bitMask);
            bitMask = bitMask >> 1;
            inputBitsLength++;
        }
    }  

    const int exponentLength = 11;
    const int maxMantissaLength = 19;

    int binaryExponent[exponentLength];
    for (int i = 0; i < exponentLength; i++)
        binaryExponent[i] = inputBits[i + 1];    
    int binaryMantissa[maxMantissaLength];
    int mantissaLength = maxMantissaLength;
    for (int i = 0; i < mantissaLength; i++)
        binaryMantissa[i] = inputBits[i + exponentLength + 1];
    while (mantissaLength > 0 && binaryMantissa[mantissaLength - 1] == 0)
        mantissaLength--;
    printf(inputBits[0] == 0 ? "+" : "-");
    printf("1.%I64u", decimalMantissa(binaryMantissa, mantissaLength));
    printf(" * 2 ^ (%I64u)\n", decimalExponent(binaryExponent, exponentLength));
    return 0;
}
