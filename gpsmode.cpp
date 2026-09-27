// File: gpsmode.cpp
// Purpose: Selective Availability pickup accuracy simulation for the GPS Ride Planner.
// Author: Bryan
// STAGE 1 STUB: returns a fixed value. Bryan replaces this with the full logic.

#include "gpsmode.h"

#include <iostream>

double simulatePickupError(int era, std::mt19937& rng) {
    (void)era;  // Unused until the real logic is written.
    (void)rng;
    return 0.0;
}

void printPickupResult(double errorMeters) {
    (void)errorMeters;  // Unused until the real logic is written.
    std::cout << "(stub)\n";
}
