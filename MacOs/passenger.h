#ifndef PASSENGER_H
#define PASSENGER_H

#include "airport.h"

void passengerMenu(Passenger passengers[], int& passengerCount,
     Flight flights[], int flightCount);

// Validation functions
bool isFlightExist(Flight flights[], int flightCount, int flightNumber);
bool isSeatOverbooking(Passenger passengers[], int passengerCount, int flightNumber, int seat);

void addPassenger(Passenger passengers[], int& passengerCount,
     Flight flights[], int flightCount);
void showPassengers(Passenger passengers[], int passengerCount);
void editPassenger(Passenger passengers[], int passengerCount);

void deletePassengerByCode(Passenger passengers[], int& passengerCount);
void deletePassengerBySurname(Passenger passengers[], int& passengerCount);
void deletePassengerByFlight(Passenger passengers[], int& passengerCount);

void searchPassengerByCode(Passenger passengers[], int passengerCount);
void searchPassengerBySurname(Passenger passengers[], int passengerCount);
void searchPassengerByFlight(Passenger passengers[], int passengerCount);

void sortPassengersByCode(Passenger passengers[], int passengerCount);
void sortPassengersBySurname(Passenger passengers[], int passengerCount);
void sortPassengersByFlight(Passenger passengers[], int passengerCount);

void deletePassenger(Passenger passengers[], int& passengerCount);
void searchPassenger(Passenger passengers[], int passengerCount);
void sortPassengers(Passenger passengers[], int passengerCount);

#endif