#include "calculations.h"
#include "airport.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void passengersOnFlight(
    Passenger passengers[],
    int passengerCount)
{
    int number;
    int count = 0;

    cout << "Enter flight number: ";
    cin >> number;

    for (int i = 0; i < passengerCount; i++)
    {
        if (passengers[i].flightNumber ==
            number)
        {
            count++;
        }
    }

    cout << "Passengers on flight: "
         << count << endl;
}

// FREE SEATS ON FLIGHT.

void freeSeatsOnFlight(
    Plane planes[], int planeCount,
    Flight flights[], int flightCount,
    Passenger passengers[], int passengerCount)
{
    int number;

    cout << "Enter flight number: ";
    cin >> number;

    int planeId = -1;

    for (int i = 0; i < flightCount; i++)
    {
        if (flights[i].number == number)
        {
            planeId = flights[i].planeId;
        }
    }

    if (planeId == -1)
    {
        cout << "Flight not found.\n";
        return;
    }

    int capacity = 0;

    for (int i = 0; i < planeCount; i++)
    {
        if (planes[i].id == planeId)
        {
            capacity = planes[i].capacity;
        }
    }

    int passengersCount = 0;

    for (int i = 0; i < passengerCount; i++)
    {
        if (passengers[i].flightNumber ==
            number)
        {
            passengersCount++;
        }
    }

    cout << "Plane capacity: "
         << capacity << endl;

    cout << "Passengers: "
         << passengersCount << endl;

    cout << "Free seats: "
         << capacity - passengersCount
         << endl;
}

// AVARAGE PLANE CAPAXITY

void averagePlaneCapacity(
    Plane planes[],
    int planeCount)
{
    if (planeCount == 0)
    {
        cout << "No planes available.\n";
        return;
    }

    int sum = 0;

    for (int i = 0; i < planeCount; i++)
    {
        sum += planes[i].capacity;
    }

    double average =
        (double)sum / planeCount;

    cout << "Average plane capacity: "
         << average << endl;
}

void flightWithMostPassengers(
    Flight flights[], int flightCount,
    Passenger passengers[], int passengerCount)
{
    if (flightCount == 0)
    {
        cout << "No flights available.\n";
        return;
    }

    int maxPassengers = 0;
    int flightWithMost = -1;

    for (int i = 0; i < flightCount; i++)
    {
        int count = 0;
        
        for (int j = 0; j < passengerCount; j++)
        {
            if (passengers[j].flightNumber == flights[i].number)
            {
                count++;
            }
        }
        
        if (count > maxPassengers)
        {
            maxPassengers = count;
            flightWithMost = flights[i].number;
        }
    }

    if (flightWithMost == -1)
    {
        cout << "No flights with passengers found.\n";
    }
    else
    {
        cout << "Flight with most passengers: " << flightWithMost << endl;
        cout << "Number of passengers: " << maxPassengers << endl;
    }
}

// CALCULATIONS MEUN

void calculationsMenu(
    Plane planes[],
    int planeCount,
    Flight flights[],
    int flightCount,
    Passenger passengers[],
    int passengerCount)
{
    int choice;

    do
    {
        cout << "\n=== CALCULATIONS ===\n";

        cout << "1 Passengers on flight\n";
        cout << "2 Free seats on flight\n";
        cout << "3 Average plane capacity\n";
        cout << "4 Flight with most passengers\n";
        cout << "5 Back to main menu\n";

        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            passengersOnFlight(
                passengers,
                passengerCount);
        }

        else if (choice == 2)
        {
            freeSeatsOnFlight(
                planes,
                planeCount,
                flights,
                flightCount,
                passengers,
                passengerCount);
        }

        else if (choice == 3)
{
    averagePlaneCapacity(
        planes,
        planeCount);
}

else if (choice == 4)
{
    flightWithMostPassengers(
        flights,
        flightCount,
        passengers,
        passengerCount);
}

else if (choice != 5)
{
    cout << "Invalid choice.\n";
}

    } while (choice != 5);
}