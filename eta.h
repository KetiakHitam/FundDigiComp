// File: eta.h
// Purpose: Arrival time estimation
// Author: Abdo
// Signatures fixed, do not change

#ifndef ETA_H
#define ETA_H

// Minutes to arrive, -1 for an unknown traffic level or ride type
int calcEtaMinutes(double roadKm, int trafficLevel, int rideType);

#endif
