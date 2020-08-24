#pragma once

enum State
{
    //numeration is for states.txt, errorState must be equal to 0
    errorState,
    emptyState = 1,
    mantissaSign = 2,
    dotAndNoDigitsInMantissa = 3,
    dotWithDigitsInMantissa = 4,
    emptyExponent = 5,
    exponentSign = 6,
    digitsInExponent = 7,
    digitsAndNoDotInMantissa = 8,
    statesNumber
};

const int charactersAmount = CHAR_MAX + 1;
void scanStateTable(const char *fileName, int nextStates[][charactersAmount], bool *stateIsCorrect);
