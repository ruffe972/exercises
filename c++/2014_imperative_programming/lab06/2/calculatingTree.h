#pragma once
#include <iostream>

struct Tree;

Tree* createTree();
void buildTreeFromFile(std::istream &file, Tree* tree);
void printDebug(Tree* tree);
void printTree(Tree* tree);
double calculateAndDelete(Tree* tree);
