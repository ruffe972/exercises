#pragma once

//! Prints ~ symbol
void debug();

//! @returns minimum of 2 integers
int min(int a, int b);

//! @returns maximum of 2 integers
int max(int a, int b);

//! Waits for user to input the file name
/*!
 * @returns dynamic C-string
 * @param defaultName is returned when the user input is empty
 */
char *readFileName(const char *defaultName);
