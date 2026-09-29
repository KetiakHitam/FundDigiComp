// File: main.cpp
// Purpose: Menu loop and integration for the GPS Ride Planner
// Author: Isac

#include <iomanip>
#include <iostream>
#include <random>
#include <string>

#include "common.h"
#include "eta.h"
#include "fare.h"
#include "gpsmode.h"
#include "input.h"
#include "location.h"

// Fixed seed for repeatable GPS error values
const unsigned int GPS_RANDOM_SEED = 2000;

// Trip set in option 1, required by options 2 to 5
struct Trip {
    bool isSet = false;
    Location pickup;
    Location dropoff;
    double straightKm = 0.0;
    double roadKm = 0.0;
};

void printMenu() {
    printTitle("GPS RIDE PLANNER");
    std::cout << "1. Set trip (pickup and drop-off)\n"
              << "2. Fare estimate\n"
              << "3. Arrival time estimate\n"
              << "4. GPS pickup accuracy (Selective Availability)\n"
              << "5. Trip receipt\n"
              << "0. Exit\n";
}

// Returns false and prints a message if no trip is set
bool requireTrip(const Trip& trip) {
    if (!trip.isSet) {
        std::cout << "Set a trip first (option 1).\n";
        return false;
    }
    return true;
}

// Shown when a module returns -1 for invalid input
void printCalculationError() {
    std::cout << "Error: invalid input to calculation.\n";
}

void setTrip(Trip& trip) {
    printTitle("SET TRIP");
    printLocationList();
    int count = getLocationCount();
    std::string range = "(1-" + std::to_string(count) + "): ";

    int pickupNumber = readInt("Pickup " + range, 1, count);
    int dropoffNumber = readInt("Drop-off " + range, 1, count);

    // Pickup and drop-off must differ
    while (dropoffNumber == pickupNumber) {
        std::cout << "Pickup and drop-off must be different.\n";
        dropoffNumber = readInt("Drop-off " + range, 1, count);
    }

    // List starts at 1, index starts at 0
    trip.pickup = getLocation(pickupNumber - 1);
    trip.dropoff = getLocation(dropoffNumber - 1);
    trip.straightKm = straightLineKm(trip.pickup, trip.dropoff);
    trip.roadKm = estimateRoadKm(trip.straightKm);
    trip.isSet = true;

    std::cout << "Trip: " << trip.pickup.name << " to " << trip.dropoff.name << "\n"
              << std::fixed << std::setprecision(2)
              << "Straight-line distance: " << trip.straightKm << " km\n"
              << "Estimated road distance: " << trip.roadKm << " km\n";
}

void showFare(const Trip& trip) {
    if (!requireTrip(trip)) {
        return;
    }
    printTitle("FARE ESTIMATE");
    int rideType = readInt("Ride type (1 Car, 2 Bike, 3 Premium): ", RIDE_CAR, RIDE_PREMIUM);
    int hour = readInt("Hour of day (0-23): ", 0, 23);
    double fare = calcFare(rideType, trip.roadKm, hour);
    if (fare < 0) {
        printCalculationError();
        return;
    }
    std::cout << std::fixed << std::setprecision(2) << "Estimated fare: RM " << fare << "\n";
    if (isPeakHour(hour)) {
        std::cout << "Peak hour surge x1.5 applied.\n";
    }
}

void showEta(const Trip& trip) {
    if (!requireTrip(trip)) {
        return;
    }
    printTitle("ARRIVAL TIME ESTIMATE");
    int trafficLevel = readInt("Traffic (1 Light, 2 Moderate, 3 Heavy): ", TRAFFIC_LIGHT, TRAFFIC_HEAVY);
    int rideType = readInt("Ride type (1 Car, 2 Bike, 3 Premium): ", RIDE_CAR, RIDE_PREMIUM);
    int minutes = calcEtaMinutes(trip.roadKm, trafficLevel, rideType);
    if (minutes < 0) {
        printCalculationError();
        return;
    }
    std::cout << "Estimated arrival: " << minutes << " min\n";
}

void showPickupAccuracy(std::mt19937& rng) {
    printTitle("GPS PICKUP ACCURACY");
    std::cout << "1 = 1990 to 2000, Selective Availability ON (civilian GPS deliberately degraded)\n"
              << "2 = after 1 May 2000, Selective Availability OFF\n";
    int era = readInt("Era (1-2): ", ERA_SA_ON, ERA_SA_OFF);
    double errorMeters = simulatePickupError(era, rng);
    if (errorMeters < 0) {
        printCalculationError();
        return;
    }
    printPickupResult(errorMeters);
}

int main() {
    Trip trip;
    std::mt19937 rng(GPS_RANDOM_SEED);
    bool running = true;

    while (running) {
        printMenu();
        int choice = readInt("Choose an option (0-5): ", 0, 5);
        switch (choice) {
            case 1:
                setTrip(trip);
                break;
            case 2:
                showFare(trip);
                break;
            case 3:
                showEta(trip);
                break;
            case 4:
                showPickupAccuracy(rng);
                break;
            case 5:
                std::cout << "Trip receipt is not available yet.\n";
                break;
            case 0:
                std::cout << "Goodbye.\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }
    return 0;
}
