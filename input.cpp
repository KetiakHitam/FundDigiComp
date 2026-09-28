// File: input.cpp
// Purpose: Validated user input and screen titles
// Author: Jimmy

#include "input.h"

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

// Removes leading and trailing spaces, tabs and carriage returns
static std::string trim(const std::string& text) {
    size_t first = text.find_first_not_of(" \t\r");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = text.find_last_not_of(" \t\r");
    return text.substr(first, last - first + 1);
}

// True if text is an optional minus sign followed by digits only
static bool isWholeNumber(const std::string& text) {
    size_t start = (!text.empty() && text[0] == '-') ? 1 : 0;
    if (start == text.size()) {
        return false;
    }
    for (size_t i = start; i < text.size(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(text[i]))) {
            return false;
        }
    }
    return true;
}

int readInt(const std::string& prompt, int minValue, int maxValue) {
    while (true) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "\nInput closed. Exiting.\n";
            std::exit(0);
        }

        std::string text = trim(line);
        if (isWholeNumber(text)) {
            try {
                int value = std::stoi(text);
                if (value >= minValue && value <= maxValue) {
                    return value;
                }
            } catch (const std::out_of_range&) {
                // Too large for int, handled as invalid below
            }
        }
        std::cout << "Please enter a whole number from " << minValue << " to " << maxValue << ".\n";
    }
}

void printTitle(const std::string& title) {
    for (int i = 0; i < 40; i++) {
        std::cout << "=";
    }
    std::cout << "\n" << title << "\n";
    for (int i = 0; i < 40; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}
