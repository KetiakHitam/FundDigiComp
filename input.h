// File: input.h
// Purpose: Validated user input and screen titles
// Author: Jimmy
// Signatures fixed, do not change

#ifndef INPUT_H
#define INPUT_H

#include <string>

// Returns a whole number from minValue to maxValue, asks again on invalid input
int readInt(const std::string& prompt, int minValue, int maxValue);

// Prints the title between two lines of '='
void printTitle(const std::string& title);

#endif
