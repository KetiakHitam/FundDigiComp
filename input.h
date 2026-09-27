// File: input.h
// Purpose: Declarations for validated user input and screen titles.
// Author: Jimmy
// Signatures are fixed. Do not change them without Isac's approval.

#ifndef INPUT_H
#define INPUT_H

#include <string>

// Prints the prompt and returns a whole number from minValue to maxValue.
// Asks again on empty, non-numeric or out-of-range input.
int readInt(const std::string& prompt, int minValue, int maxValue);

// Prints the title between two lines of 40 '=' characters.
void printTitle(const std::string& title);

#endif
