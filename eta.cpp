// Temporary test only. Do NOT git add this file.
#include <iostream>
#include "eta.h"

int main() {
    std::cout << calcEtaMinutes(10, 1, 1) << " (15)\n";
    std::cout << calcEtaMinutes(10, 2, 1) << " (24)\n";
    std::cout << calcEtaMinutes(10, 3, 1) << " (50)\n";
    std::cout << calcEtaMinutes(10, 3, 2) << " (30)\n";
    std::cout << calcEtaMinutes(10, 1, 2) << " (15)\n";
    std::cout << calcEtaMinutes(0.1, 1, 1) << " (1)\n";
    std::cout << calcEtaMinutes(10, 4, 1) << " (-1)\n";
    std::cout << calcEtaMinutes(10, 1, 5) << " (-1)\n";
    return 0;
}
