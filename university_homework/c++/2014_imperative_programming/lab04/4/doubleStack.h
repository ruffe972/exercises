#pragma once

struct DoubleStackElement;
struct DoubleStack;

DoubleStack *createDoubleStack();

void deleteDoubleStack(DoubleStack *stack);

double popDouble(DoubleStack *stack);

double topDouble(DoubleStack *stack);

void appendDouble(double value, DoubleStack *stack);

void printDoubleStack(DoubleStack *stack);

int doubleStackSize(DoubleStack *stack);
