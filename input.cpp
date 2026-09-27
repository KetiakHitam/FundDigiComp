// File: input.cpp
// Purpose: Validated user input and screen titles.
// Author: Jimmy
// STAGE 1 STUB: reads a number with no validation. Jimmy replaces this with the full logic.

#include "input.h"

#include <cstdlib>
#include <iostream>
#include <limits>

int readInt(const std::string& prompt, int minValue, int maxValue) {
    (void)maxValue;  // Unused until the real validation is written.
    std::cout << prompt;
    int value = 0;
    if (!(std::cin >> value)) {
        if (std::cin.eof()) {
            std::cout << "\nInput closed. Exiting.\n";
            std::exit(0);
        }
        // Discard the bad input so the menu does not loop forever.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return minValue - 1;
    }
    return value;
}

void printTitle(const std::string& title) {
    std::cout << "\n" << title << "\n";
}
