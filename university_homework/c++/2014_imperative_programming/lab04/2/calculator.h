#pragma once

const int maxStringLen = 1000;

char *infixToPostfix(char *infixString, char *postfixString);

double calculateFromPostfix(char *string);

double calculate(char *infixString);
