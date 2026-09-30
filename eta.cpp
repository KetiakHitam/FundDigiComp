// File: eta.cpp
// Purpose: Arrival time estimate for the GPS Ride Planner.
// Author: Abdo

#include "eta.h"
#include "common.h"
#include <cmath>

// Average speeds in km/h
const double SPEED_LIGHT_KMH = 40.0;
const double SPEED_MODERATE_KMH = 25.0;
const double SPEED_HEAVY_KMH = 12.0;
const double SPEED_BIKE_HEAVY_KMH = 20.0;

int calcEtaMinutes(double roadKm, int trafficLevel, int rideType) {
    double speedKmh;
    switch (trafficLevel) {
        case TRAFFIC_LIGHT:
            speedKmh = SPEED_LIGHT_KMH;
            break;
        case TRAFFIC_MODERATE:
            speedKmh = SPEED_MODERATE_KMH;
            break;
        case TRAFFIC_HEAVY:
            speedKmh = SPEED_HEAVY_KMH;
            break;
        default:
            return -1;
    }

    // bikes can squeeze between cars, so heavy traffic slows them less
    if (rideType == RIDE_BIKE && trafficLevel == TRAFFIC_HEAVY) {
        speedKmh = SPEED_BIKE_HEAVY_KMH;
    }

    // hours -> minutes, always round up so we never promise too early
    double minutes = std::ceil(roadKm / speedKmh * 60.0);

    return static_cast<int>(minutes);
}
