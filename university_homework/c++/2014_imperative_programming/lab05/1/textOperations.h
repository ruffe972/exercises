#pragma once

void setStringLen(int stringLen, char *string);

void scanString(char *string, int maxStringLen);

void addSymbolToString(char symbol, char *string, int& stringLen);

int symbolToDigit(char symbol);

bool isDigit(char symbol);

bool isLetter(char symbol);

char symbolToLowerCase(char symbol);
