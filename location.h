// File: location.h
// Purpose: Declarations for the place list and GPS distance calculation.
// Author: Teh En Tong
// Signatures are fixed. Do not change them without Isac's approval.

#ifndef LOCATION_H
#define LOCATION_H

#include <string>

// A place with its GPS coordinates in decimal degrees.
struct Location {
    std::string name;
    double latitude;
    double longitude;
};

// Number of places in the list.
int getLocationCount();

// Returns the place at index 0 to getLocationCount() - 1.
Location getLocation(int index);

// Prints the places numbered from 1.
void printLocationList();

// Great-circle distance between two places in km (haversine formula).
double straightLineKm(const Location& from, const Location& to);

// Estimated road distance in km from a straight-line distance.
double estimateRoadKm(double straightKm);

#endif
