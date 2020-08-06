#pragma once
#include <string>

/// Waits for user to input the file name
/** @param defaultName is returned when the user input is empty */
std::string readFileName(const char *defaultName = "input.txt");
