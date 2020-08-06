#pragma once
#include <climits>
#include "stringList.h"
#include "ershovString.h"
using namespace stringList;

void deleteContents(List **hashArray);
void update(List **hashArray, String *string);
int stringOccurences(List **hashArray, String *string);
void printAnalysis(std::ostream &file, List **hashArray);
