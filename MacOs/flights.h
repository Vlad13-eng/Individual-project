#ifndef FLIGHTS_H
#define FLIGHTS_H

#include "airport.h"

void flightsMenu(Flight flights[], int& flightCount, 
     Plane planes[], int planeCount,
     Passenger passengers[], int& passengerCount);

// Cascade delete for related passengers
void cascadeDeletePassengersOnFlight(Passenger passengers[], int& passengerCount, int flightNumber);

void addFlight(Flight flights[], int& flightCount, Plane planes[], int planeCount);
void showFlights(Flight flights[], int flightCount);
void editFlight(Flight flights[], int flightCount);

void searchFlightsByNumber(Flight flights[], int flightCount);
void searchFlightsByDestination(Flight flights[], int flightCount);
void searchFlightsByDate(Flight flights[], int flightCount);

void sortFlightsByNumber(Flight flights[], int flightCount);
void sortFlightsByDestination(Flight flights[], int flightCount);
void sortFlightsByDate(Flight flights[], int flightCount);

void deleteFlightbyNumber(Flight flights[], int& flightCount,
     Passenger passengers[], int& passengerCount);
void deleteFlightbyDestination(Flight flights[], int& flightCount,
     Passenger passengers[], int& passengerCount);
void deleteFlightbyDate(Flight flights[], int& flightCount,
     Passenger passengers[], int& passengerCount);

void deleteFlight(Flight flights[], int& flightCount,
     Passenger passengers[], int& passengerCount);
void searchFlights(Flight flights[], int flightCount);
void sortFlights(Flight flights[], int flightCount);

#endif