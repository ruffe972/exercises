#pragma once
#include <stdio.h>

const int maxStringLength = 100;

void scanString(char *string, int &stringLen, FILE *file);

int toDigit(char symbol);
bool isDigit(char symbol);
bool isLetter(char symbol);
char symbolToLowerCase(char symbol);
