#include "airport.h"
#include "planes.h"
#include "flights.h"
#include "passenger.h"
#include "calculations.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    Plane planes[MAX_PLANES];
    Flight flights[MAX_FLIGHTS];
    Passenger passengers[MAX_PASSENGERS];

    int planeCount = 0;
    int flightCount = 0;
    int passengerCount = 0;

    // LOAD PLANES

    ifstream planeFile("planes.txt");

    if (!planeFile)
    {
        cout << "planes.txt not found. New file will be created.\n";
    }
    else
    {
        while (planeFile >> planes[planeCount].id
            >> planes[planeCount].model
            >> planes[planeCount].manufacturer
            >> planes[planeCount].capacity)
        {
            planeCount++;
        }

        planeFile.close();
    }

    // LOAD FLIGHTS

    ifstream flightFile("flights.txt");

    if (!flightFile)
    {
        cout << "flights.txt not found. New file will be created.\n";
    }
    else
    {
        while (flightFile >> flights[flightCount].number
            >> flights[flightCount].destination
            >> flights[flightCount].departureDate.day)
        {
            int monthInt;
            flightFile >> monthInt
                >> flights[flightCount].departureDate.year
                >> flights[flightCount].planeId;
            flights[flightCount].departureDate.month = static_cast<Month>(monthInt);
            flightCount++;
        }

        flightFile.close();
    }

    // LOAD PASSENGERS 

    ifstream passengerFile("passengers.txt");

    if (!passengerFile)
    {
        cout << "passengers.txt not found. New file will be created.\n";
    }
    else
    {
        while (passengerFile >> passengers[passengerCount].code
            >> passengers[passengerCount].surname
            >> passengers[passengerCount].name
            >> passengers[passengerCount].flightNumber
            >> passengers[passengerCount].seat)
        {
            passengerCount++;
        }

        passengerFile.close();
    }


    int choice = -1;

    do
    {
        cout << "\n===== AIRPORT SYSTEM =====\n";

        cout << "1. Planes\n";
        cout << "2. Flights\n";
        cout << "3. Passengers\n";
        cout << "4. Calculations\n";

        cout << "0. Exit(Save)\n";

        cout << "Choose: ";
        cin >> choice;

        // PLANES

        if (choice == 1)
        {
            planesMenu(planes, planeCount);
        }

        // FLIGHTS

        else if (choice == 2)
        {
            flightsMenu(flights, flightCount,
                        planes, planeCount,
                        passengers, passengerCount);
        }

        // PASSENGERS =================

        else if (choice == 3)
        {
            passengerMenu(passengers, passengerCount, flights, flightCount);
        }

        else if (choice == 4)
        {
        calculationsMenu(
        planes,
        planeCount,
        flights,
        flightCount,
        passengers,
        passengerCount);
        }

        else if (choice != 0)
        {
            cout << "Invalid choice.\n";
        }

        

    } while (choice != 0);

    // SAVE PLANES

    ofstream savePlanes("planes.txt");

    if (!savePlanes)
    {
        cout << "Error saving planes.\n";
    }
    else
    {
        for (int i = 0; i < planeCount; i++)
        {
            savePlanes << planes[i].id << " "
                << planes[i].model << " "
                << planes[i].manufacturer << " "
                << planes[i].capacity
                << endl;
        }

        savePlanes.close();
    }

    // SAVE FLIGHTS

    ofstream saveFlights("flights.txt");

    if (!saveFlights)
    {
        cout << "Error saving flights.\n";
    }
    else
    {
        for (int i = 0; i < flightCount; i++)
        {
            saveFlights << flights[i].number << " "
                << flights[i].destination << " "
                << flights[i].departureDate.day << " "
                << static_cast<int>(flights[i].departureDate.month) << " "
                << flights[i].departureDate.year << " "
                << flights[i].planeId
                << endl;
        }

        saveFlights.close();
    }

    // SAVE PASSENGERS

    ofstream savePassengers("passengers.txt");

    if (!savePassengers)
    {
        cout << "Error saving passengers.\n";
    }
    else
    {
        for (int i = 0; i < passengerCount; i++)
        {
            savePassengers << passengers[i].code << " "
                << passengers[i].surname << " "
                << passengers[i].name << " "
                << passengers[i].flightNumber << " "
                << passengers[i].seat
                << endl;
        }

        savePassengers.close();
    }

    cout << "\nData saved successfully.\n";

    return 0;
}