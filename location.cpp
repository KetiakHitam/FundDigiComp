// File: location.cpp
// Purpose: Place list and GPS distance calculation.
// Author: Teh En Tong
// STAGE 1 STUB: two placeholder places and a fixed 10 km distance. Teh replaces this with the full logic.

#include "location.h"

#include <iostream>

const int STUB_LOCATION_COUNT = 6;
const Location STUB_LOCATIONS[STUB_LOCATION_COUNT] = {
    {"MMU Cyberjaya",            2.9276, 101.6413},
    {"KLCC",                     3.1579, 101.7116},
    {"KL Sentral",               3.1340, 101.6865},
    {"Mid Valley Megamall",      3.1180, 101.6770},
    {"Dataran Putra, Putrajaya", 2.9360, 101.6897},
    {"KLIA Terminal 1",          2.7456, 101.7072},
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
