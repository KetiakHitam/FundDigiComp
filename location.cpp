// File: location.cpp
// Purpose: Place list and GPS distance calculation.
// Author: Teh En Tong

#include "location.h"

#include <cmath>
#include <iostream>

const double PI = 3.14159265358979;

// The six places, in the required order. Coordinates rounded to 4 decimals.
const int LOCATION_COUNT = 6;
const Location LOCATIONS[LOCATION_COUNT] = {
    {"MMU Cyberjaya",            2.9276, 101.6413},
    {"KLCC",                     3.1579, 101.7116},
    {"KL Sentral",               3.1340, 101.6865},
    {"Mid Valley Megamall",      3.1180, 101.6770},
    {"Dataran Putra, Putrajaya", 2.9360, 101.6897},
    {"KLIA Terminal 1",          2.7456, 101.7072},
};

int getLocationCount() {
    return LOCATION_COUNT;
}

Location getLocation(int index) {
    return LOCATIONS[index];  // Main only passes valid indexes (0 to 5).
}

void printLocationList() {
    for (int i = 0; i < LOCATION_COUNT; i++) {
        std::cout << (i + 1) << ". " << LOCATIONS[i].name << "\n";
    }
}

// Converts degrees to radians.
static double toRadians(double degrees) {
    return degrees * PI / 180.0;
}

double straightLineKm(const Location& from, const Location& to) {
    const double EARTH_RADIUS_KM = 6371.0;

    double lat1 = toRadians(from.latitude);
    double lon1 = toRadians(from.longitude);
    double lat2 = toRadians(to.latitude);
    double lon2 = toRadians(to.longitude);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double sinLat = std::sin(dLat / 2);
    double sinLon = std::sin(dLon / 2);
    double a = sinLat * sinLat + std::cos(lat1) * std::cos(lat2) * sinLon * sinLon;
    double c = 2 * std::asin(std::sqrt(a));

    return EARTH_RADIUS_KM * c;
}

double estimateRoadKm(double straightKm) {
    return straightKm * 1.3;  // 1.3 is the group's assumption, because roads are not straight lines.
}
