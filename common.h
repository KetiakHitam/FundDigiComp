// File: common.h
// Purpose: Shared constants for ride types, traffic levels and GPS eras.
// Author: Isac

#ifndef COMMON_H
#define COMMON_H

// Ride types (user enters 1 to 3).
const int RIDE_CAR = 1;
const int RIDE_BIKE = 2;
const int RIDE_PREMIUM = 3;

// Traffic levels (user enters 1 to 3).
const int TRAFFIC_LIGHT = 1;
const int TRAFFIC_MODERATE = 2;
const int TRAFFIC_HEAVY = 3;

// GPS eras. SA = Selective Availability, the deliberate civilian accuracy limit (1990 to 1 May 2000).
const int ERA_SA_ON = 1;
const int ERA_SA_OFF = 2;

#endif
