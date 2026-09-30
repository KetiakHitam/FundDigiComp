// File: gpsmode.cpp
// Purpose: Selective Availability pickup accuracy simulation for the GPS Ride Planner
// Author: Bryan
// Disclaimer: error ranges are invented by the group, not official GPS figures
// Ranges model Selective Availability (about 100 m) versus after May 2000 (about 20 m)

#include "gpsmode.h"
#include "common.h"
#include <iostream>
#include <iomanip>
#include <random>

const double SA_ON_MIN_ERROR = 10.0;
const double SA_ON_MAX_ERROR = 100.0;
const double SA_OFF_MIN_ERROR = 2.0;
const double SA_OFF_MAX_ERROR = 20.0;

const double VERDICT_THRESHOLD_OK = 20.0;
const double VERDICT_THRESHOLD_CLOSE = 50.0;

double simulatePickupError(int era, std::mt19937& rng) {
    if (era == ERA_SA_ON) {
        std::uniform_real_distribution dist(SA_ON_MIN_ERROR, SA_ON_MAX_ERROR);
        return dist(rng);
    } else if (era == ERA_SA_OFF) {
        std::uniform_real_distribution dist(SA_OFF_MIN_ERROR, SA_OFF_MAX_ERROR);
        return dist(rng);
    } else {
        return -1.0;
    }
}

void printPickupResult(double errorMeters) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Estimated GPS error: " << errorMeters << " m\n";

    if (errorMeters <= VERDICT_THRESHOLD_OK) {
        std::cout << "Pickup OK: the driver will find you.\n";
    } else if (errorMeters <= VERDICT_THRESHOLD_CLOSE) {
        std::cout << "Pickup close: the driver may need to call you.\n";
    } else {
        std::cout << "Warning: the driver may go to the wrong pickup point.\n";
    }
}
