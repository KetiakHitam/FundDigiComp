// File: location.cpp
// Purpose: Place list and GPS distance calculation.
// Author: Teh En Tong
// STAGE 1 STUB: two placeholder places and a fixed 10 km distance. Teh replaces this with the full logic.

#include "location.h"

#include <iostream>

const int STUB_LOCATION_COUNT = 2;
const Location STUB_LOCATIONS[STUB_LOCATION_COUNT] = {
    {"Place A (stub)", 0.0, 0.0},
    {"Place B (stub)", 0.0, 0.0},
};

int getLocationCount() {
    return STUB_LOCATION_COUNT;
}

Location getLocation(int index) {
    // Stub guard: the stub input has no range check yet.
    if (index < 0 || index >= STUB_LOCATION_COUNT) {
        return STUB_LOCATIONS[0];
    }
    return STUB_LOCATIONS[index];
}

void printLocationList() {
    for (int i = 0; i < STUB_LOCATION_COUNT; i++) {
        std::cout << (i + 1) << ". " << STUB_LOCATIONS[i].name << "\n";
    }
}

double straightLineKm(const Location& from, const Location& to) {
    (void)from;  // Unused until the haversine formula is written.
    (void)to;
    return 10.0;
}

double estimateRoadKm(double straightKm) {
    return straightKm;
} 
