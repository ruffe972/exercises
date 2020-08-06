#pragma once

struct CharStackElement;
struct CharStack;

CharStack *createCharStack();

void deleteCharStack(CharStack *stack);

char popChar(CharStack *stack);

char topChar(CharStack *stack);

void appendChar(char value, CharStack *stack);

void printCharStack(CharStack *stack);

int charStackSize(CharStack *stack);
