// File: gpsmode.h
// Purpose: Selective Availability pickup accuracy simulation
// Author: Bryan
// Signatures fixed, do not change

#ifndef GPSMODE_H
#define GPSMODE_H

#include <random>

// GPS error in metres, -1.0 for an unknown era
double simulatePickupError(int era, std::mt19937& rng);

// Prints the error and the pickup verdict
void printPickupResult(double errorMeters);

#endif
