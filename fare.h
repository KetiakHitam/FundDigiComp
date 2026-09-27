// File: fare.h
// Purpose: Declarations for fare calculation.
// Author: Ayman
// Signatures are fixed. Do not change them without Isac's approval.

#ifndef FARE_H
#define FARE_H

// True for peak hours 7, 8, 17, 18 and 19.
bool isPeakHour(int hour);

// Fare in RM for a ride type (see common.h), road distance in km and hour 0 to 23.
// Returns -1.0 for an unknown ride type.
double calcFare(int rideType, double roadKm, int hour);

#endif
