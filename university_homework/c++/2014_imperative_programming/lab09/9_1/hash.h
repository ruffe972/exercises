#pragma once
#include <climits>
#include "stringList.h"
#include "ershovString.h"
using namespace stringList;

typedef unsigned short int hashType;
const int maxHashSize = USHRT_MAX;
const hashType hashBase = 101;

hashType hash(String *string);
void deleteContents(List **hashArray);
void update(List **hashArray, String *string);
int stringOccurences(List **hashArray, String *string);
