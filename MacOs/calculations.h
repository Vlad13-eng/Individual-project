#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "airport.h"

void calculationsMenu(
    Plane planes[], int planeCount,
    Flight flights[], int flightCount,
    Passenger passengers[], int passengerCount);

void passengersOnFlight(
    Passenger passengers[], int passengerCount);

void freeSeatsOnFlight(
    Plane planes[], int planeCount,
    Flight flights[], int flightCount,
    Passenger passengers[], int passengerCount);

void averagePlaneCapacity(
    Plane planes[], int planeCount);

void flightWithMostPassengers(Flight flights[], int flightCount,
    Passenger passengers[], int passengerCount);

#endif