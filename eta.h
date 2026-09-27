// File: eta.h
// Purpose: Declarations for arrival time estimation.
// Author: Abdo
// Signatures are fixed. Do not change them without Isac's approval.

#ifndef ETA_H
#define ETA_H

// Minutes to arrive for a road distance in km, traffic level and ride type (see common.h).
// Returns -1 for an unknown traffic level or ride type.
int calcEtaMinutes(double roadKm, int trafficLevel, int rideType);

#endif
