# GPS Ride Planner

LDCW6123 Fundamentals of Digital Competence for Programmer, Group Project Part 2, Section FCI4.

A terminal ride planner modelled on Grab, written in C++17. The user picks a pickup and a drop-off from a list of Klang Valley places. The program uses their GPS coordinates to calculate the distance, then estimates the fare, the arrival time and the GPS pickup accuracy.

The program is based on Part 1 of the project: a poster tracing GPS through Brian Winston's model of innovation.

## Menu

| Option | User enters | Program shows | Link to Part 1 |
| --- | --- | --- | --- |
| 1. Set trip | Pickup and drop-off from the place list | Straight-line and estimated road distance in km | Positioning, the core function of GPS |
| 2. Fare estimate | Ride type (1 Car, 2 Bike, 3 Premium), hour of day (0-23) | Fare in RM, peak-hour surge | Spin-offs: MyTeksi / Grab (2012) |
| 3. Arrival time | Traffic (1 Light, 2 Moderate, 3 Heavy), ride type | Minutes to arrive | Spin-offs: MyTeksi / Grab (2012) |
| 4. GPS pickup accuracy | Era (1 = 1990 to 2000, 2 = after May 2000) | GPS error in metres and a pickup verdict | Suppression: Selective Availability (1990 to 2000) |
| 5. Trip receipt | Ride type, hour, traffic, era | All results together | Diffusion: GPS in every phone |
| 0. Exit | Nothing | Ends the program | |

Invalid input (letters, decimals, empty input, out-of-range numbers) is rejected and the user is asked again.

## Disclaimer

All rates, speeds and error ranges in this program are invented by the group. They are not real Grab prices or official GPS figures.

## Build and run

Requires a C++17 compiler (g++).

```
g++ -std=c++17 -Wall -Wextra -o rideplanner main.cpp input.cpp location.cpp fare.cpp eta.cpp gpsmode.cpp
```

- Windows: `.\rideplanner.exe`
- Mac / Linux: `./rideplanner`

## Files

| File | Purpose | Author |
| --- | --- | --- |
| main.cpp | Menu loop, trip state, receipt | Isac |
| common.h | Shared constants | Isac |
| input.h / input.cpp | Validated number input, screen titles | Jimmy |
| location.h / location.cpp | Place list, GPS distance (haversine) | Teh En Tong |
| fare.h / fare.cpp | Fare and peak-hour surge | Ayman |
| eta.h / eta.cpp | Arrival time estimate | Abdo |
| gpsmode.h / gpsmode.cpp | Selective Availability pickup accuracy simulation | Bryan |
| TESTING.md | Test cases and results | Jimmy |
