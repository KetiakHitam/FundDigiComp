// File: gpsmode.h
// Purpose: Declarations for the Selective Availability pickup accuracy simulation.
// Author: Bryan
// Signatures are fixed. Do not change them without Isac's approval.

#ifndef GPSMODE_H
#define GPSMODE_H

#include <random>

// Random GPS position error in metres for an era (see common.h). Returns -1.0 for an unknown era.
// The generator is created and seeded in main.cpp.
double simulatePickupError(int era, std::mt19937& rng);

// Prints the error and the pickup verdict.
void printPickupResult(double errorMeters);

#endif
