#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

const int MAX_PLANES = 50;
const int MAX_FLIGHTS = 100;
const int MAX_PASSENGERS = 200;

// ================= ENUMERATIONS =================

enum Month
{
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
};

// ================= STRUCTURES =================

struct Date
{
    int day;
    Month month;
    int year;
};

struct Plane
{
    int id;
    char model[30];
    char manufacturer[30];
    int capacity;
};

struct Flight
{
    int number;
    char destination[30];
    Date departureDate;
    int planeId;
};

struct Passenger
{
    int code;
    char surname[30];
    char name[30];
    int flightNumber;
    int seat;
};

void planesMenu(Plane planes[], int& planeCount);

void flightsMenu(Flight flights[], int& flightCount, Plane planes[], int planeCount);

void passengerMenu(Passenger passengers[], int& passengerCount);

#endif