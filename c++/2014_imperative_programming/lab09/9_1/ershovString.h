#pragma once
#include <iostream>

struct String;

String *createString();
void deleteString(String *&string);
char *toCString(String *string);

//leftBorder is included, right is not.
String *substring(String *string, int leftBorder, int rightBorder);
String *clone(String *string);
String *concatenate(String *string1, String *string2);

void print(std::ostream &output, String *string);
bool scan(std::istream &input, String *string);
bool scanLine(std::istream &input, String *string);

bool areEqual(String *string1, String *string2);
int &len(String *string);
bool isEmpty(String *string);
char &charAt(String *string, int index);
