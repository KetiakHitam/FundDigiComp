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

// Fare multiplier during peak hours
const double SURGE_MULTIPLIER = 1.5;

// Peak hours: 7:00-8:59 and 17:00-19:59
bool isPeakHour(int hour) {
    return hour == 7 || hour == 8 || hour == 17 || hour == 18 || hour == 19;
}

// Returns the fare in RM, or -1.0 for an unknown ride type.
double calcFare(int rideType, double roadKm, int hour) {
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

    // Step 2: base fare plus the distance charge
    double fare = baseFare + ratePerKm * roadKm;

    // Step 3: surge pricing during peak hours
    if (isPeakHour(hour)) {
        fare = fare * SURGE_MULTIPLIER;
    }

    // Step 5: not rounded here, main prints 2 decimals
    return fare;
}
