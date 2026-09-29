// File: fare.cpp
// Purpose: Fare calculation for the GPS Ride Planner.
// Author: Ayman

#include "fare.h"
#include "common.h"  // ride type constants

// Base fare (RM) per ride type
const double CAR_BASE_FARE     = 4.00;
const double BIKE_BASE_FARE    = 2.00;
const double PREMIUM_BASE_FARE = 7.00;

// Rate per km (RM) per ride type
const double CAR_RATE_PER_KM     = 1.20;
const double BIKE_RATE_PER_KM    = 0.80;
const double PREMIUM_RATE_PER_KM = 2.00;

bool isPeakHour(int hour) {
    (void)hour;  // Unused until the real logic is written.
    return false;
}

// Returns the fare in RM, or -1.0 for an unknown ride type.
double calcFare(int rideType, double roadKm, int hour) {
    (void)hour;  // Unused until the peak-hour surge is added.

    double baseFare = 0.0;
    double ratePerKm = 0.0;

    // Step 1: choose the base fare and rate for this ride type
    switch (rideType) {
        case RIDE_CAR:
            baseFare = CAR_BASE_FARE;
            ratePerKm = CAR_RATE_PER_KM;
            break;
        case RIDE_BIKE:
            baseFare = BIKE_BASE_FARE;
            ratePerKm = BIKE_RATE_PER_KM;
            break;
        case RIDE_PREMIUM:
            baseFare = PREMIUM_BASE_FARE;
            ratePerKm = PREMIUM_RATE_PER_KM;
            break;
        default:
            return -1.0;  // unknown ride type, main reports the error
    }

    //base fare plus the distance charge
    double fare = baseFare + ratePerKm * roadKm;

    //not rounded here, main prints 2 decimals
    return fare;
}
