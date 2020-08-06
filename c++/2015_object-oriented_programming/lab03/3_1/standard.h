#pragma once

typedef unsigned int UInt;

//! Print ~ symbol
void debug();

//! Waits for user to input the file name
/*!
 * @returns dynamic C-string
 * @param defaultName is returned when the user input is empty
 */
char *readFileName(const char *defaultName);

//! Check if the file contents are equal to the string
bool fileIsEqualToString(const char *fileName, const char *string);
