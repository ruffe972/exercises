#pragma once

void setStringLen(int stringLen, char *string);

void scanString(char *string, int maxStringLen);

void addSymbol(char symbol, char *string, int& stringLen);

int symbolToDigit(char symbol);

bool symbolIsDigit(char symbol);
