// File: location.h
// Purpose: Place list and GPS distance
// Author: Teh En Tong
// Signatures fixed, do not change

#ifndef LOCATION_H
#define LOCATION_H

#include <string>

// Place with GPS coordinates in decimal degrees
struct Location {
    std::string name;
    double latitude;
    double longitude;
};

// Number of places
int getLocationCount();

// Place at index 0 to count - 1
Location getLocation(int index);

// Prints places numbered from 1
void printLocationList();

// Straight-line distance in km (haversine)
double straightLineKm(const Location& from, const Location& to);

// Road distance estimate in km
double estimateRoadKm(double straightKm);

#endif
