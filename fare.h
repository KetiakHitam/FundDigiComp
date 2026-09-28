// File: fare.h
// Purpose: Fare calculation
// Author: Ayman
// Signatures fixed, do not change

#ifndef FARE_H
#define FARE_H

// True for hours 7, 8, 17, 18, 19
bool isPeakHour(int hour);

// Fare in RM, -1.0 for an unknown ride type
double calcFare(int rideType, double roadKm, int hour);

#endif
