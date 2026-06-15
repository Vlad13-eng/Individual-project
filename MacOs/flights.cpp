#include "flights.h"
#include "airport.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// ============ CASCADE DELETE FUNCTION ============

void cascadeDeletePassengersOnFlight(Passenger passengers[], int& passengerCount, int flightNumber)
{
    for (int i = 0; i < passengerCount; i++)
    {
        if (passengers[i].flightNumber == flightNumber)
        {
            for (int j = i; j < passengerCount - 1; j++)
            {
                passengers[j] = passengers[j + 1];
            }
            passengerCount--;
            i--;
        }
    }
}

void addFlight(Flight flights[], int& flightCount, Plane planes[], int planeCount){

        cout << "Flight number: ";
        cin >> flights[flightCount].number;

        for (int i = 0; i < flightCount; i++)
{
    if (flights[i].number == flights[flightCount].number)
    {
        cout << "Flight number already exists.\n";
        return;
    }
}

        if (flights[flightCount].number <= 0)
{
    cout << "Invalid flight number.\n";
    return;
}

        cout << "Destination: ";
        cin >> flights[flightCount].destination;

        cout << "Departure date (day month year): ";

        int monthInput;
        cin >> flights[flightCount].departureDate.day
            >> monthInput
            >> flights[flightCount].departureDate.year;

if (flights[flightCount].departureDate.day < 1 ||
    flights[flightCount].departureDate.day > 31 ||
    monthInput < 1 ||
    monthInput > 12 ||
    flights[flightCount].departureDate.year < 2026)
{
    cout << "Invalid date.\n";
    return;
}

        flights[flightCount].departureDate.month = static_cast<Month>(monthInput);

        cout << "Plane ID: ";
        cin >> flights[flightCount].planeId;

        bool found = false;

for (int i = 0; i < planeCount; i++)
{
    if (planes[i].id ==
        flights[flightCount].planeId)
    {
        found = true;
    }
}

if (!found)
{
    cout << "Plane not found.\n";
    cout << "Flight cannot be created.\n";

    return;
}

        flightCount++;

        cout << "Flight added successfully.\n";

        showFlights(flights, flightCount);

    }

    void showFlights(Flight flights[], int flightCount)
{
    if (flightCount == 0)
    {
        cout << "No flights available.\n";
        return;
    }

    cout << "\n==================== FLIGHTS ====================\n";

    cout << left
         << setw(12) << "Number"
         << setw(20) << "Destination"
         << setw(18) << "Date"
         << setw(12) << "PlaneID"
         << endl;

    cout << "------------------------------------------------------\n";

    for (int i = 0; i < flightCount; i++)
    {
        cout << left
             << setw(12) << flights[i].number
             << setw(20) << flights[i].destination;

        cout << setw(2) << flights[i].departureDate.day << "/"
             << setw(2) << flights[i].departureDate.month << "/"
             << setw(13) << flights[i].departureDate.year;

        cout << setw(12) << flights[i].planeId
             << endl;
    }
}

    void editFlight(Flight flights[],
    int flightCount){
        int number;
        bool found = false;

        cout << "Enter flight number: ";
        cin >> number;

        for (int i = 0; i < flightCount; i++)
        {
            if (flights[i].number == number)
            {
                cout << "New destination: ";
                cin >> flights[i].destination;

                found = true;

                cout << "Flight updated.\n";

                showFlights(flights, flightCount);
            }
        }

        if (!found)
        {
            cout << "Flight not found.\n";
        }
    }

    void searchFlights(Flight flights[],
    int flightCount){

        int choice;
        
        cout << "\n=== SEARCH FLIGHTS ===\n";
        cout << "1 Search by number\n";
        cout << "2 Search by destination\n";
        cout << "3 Search by date\n";

        cout << "Choose: ";
        cin >> choice;

        switch (choice){
    case 1: searchFlightsByNumber(flights, flightCount);
        break;

    case 2: searchFlightsByDestination(flights, flightCount);
        break;

    case 3: searchFlightsByDate(flights, flightCount);
        break;
    
    default: cout << "Invalid choice. (enter a number 1-3)\n";
        
        }
    }

    void searchFlightsByNumber(Flight flights[], int flightCount){
        int number;
        bool found = false;
        int foundIndex = -1;

        cout << "Enter flight number: ";
        cin >> number;

                        cout << left
     << setw(12) << "Number"
     << setw(20) << "Destination"
     << setw(18) << "Departure Date"
     << setw(12) << "Plane ID"
     << endl;

cout << "------------------------------------------------------\n";

        for (int i = 0; i < flightCount; i++)
        {
            if (flights[i].number == number)
            {

cout << left
     << setw(12) << flights[i].number
     << setw(20) << flights[i].destination;

cout << setw(2) << flights[i].departureDate.day << "/"
     << setw(2) << flights[i].departureDate.month << "/"
     << setw(13) << flights[i].departureDate.year;

cout << setw(12) << flights[i].planeId
     << endl;


                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "Flight not found.\n";
        }
        else
        {
            char response;
            cout << "Delete this flight? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < flightCount - 1;
                    j++)
                {
                    flights[j] = flights[j + 1];
                }

                flightCount--;
                cout << "Flight deleted.\n";
            }
        }
    }

    void searchFlightsByDestination(Flight flights[], int flightCount){
        char destination[30];
        bool found = false;
        int foundIndex = -1;

        cout << "Enter destination: ";
        cin >> destination;

                        cout << left
     << setw(12) << "Number"
     << setw(20) << "Destination"
     << setw(18) << "Departure Date"
     << setw(12) << "Plane ID"
     << endl;

cout << "------------------------------------------------------\n";

        for (int i = 0; i < flightCount; i++)
        {
            if (strcmp(flights[i].destination,
                destination) == 0)
            {

cout << left
     << setw(12) << flights[i].number
     << setw(20) << flights[i].destination;

cout << setw(2) << flights[i].departureDate.day << "/"
     << setw(2) << flights[i].departureDate.month << "/"
     << setw(13) << flights[i].departureDate.year;

cout << setw(12) << flights[i].planeId
     << endl;


                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "No flights found.\n";
        }
        else
        {
            char response;
            cout << "Delete this flight? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < flightCount - 1;
                    j++)
                {
                    flights[j] = flights[j + 1];
                }

                flightCount--;
                cout << "Flight deleted.\n";
            }
        }
    }

    void searchFlightsByDate(Flight flights[], int flightCount){
        int d, m, y;
        bool found = false;
        int foundIndex = -1;

        cout << "Enter date (day month year): ";
        cin >> d >> m >> y;

                        cout << left
     << setw(12) << "Number"
     << setw(20) << "Destination"
     << setw(18) << "Departure Date"
     << setw(12) << "Plane ID"
     << endl;

cout << "------------------------------------------------------\n";

        for (int i = 0; i < flightCount; i++)
        {
            if (flights[i].departureDate.day == d &&
                flights[i].departureDate.month == m &&
                flights[i].departureDate.year == y)
            {

cout << left
     << setw(12) << flights[i].number
     << setw(20) << flights[i].destination;

cout << setw(2) << flights[i].departureDate.day << "/"
     << setw(2) << flights[i].departureDate.month << "/"
     << setw(13) << flights[i].departureDate.year;

cout << setw(12) << flights[i].planeId
     << endl;

                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "No flights found.\n";
        }
        else
        {
            char response;
            cout << "Delete this flight? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < flightCount - 1;
                    j++)
                {
                    flights[j] = flights[j + 1];
                }

                flightCount--;
                cout << "Flight deleted.\n";
            }
        }
    }

    void sortFlights(Flight flights[],
    int flightCount){
        int choice;

        cout << "\n=== SORT FLIGHTS ===\n";
        cout << "1 Sort by number\n";
        cout << "2 Sort by destination\n";
        cout << "3 Sort by date\n";

        cout << "Choose: ";
        cin >> choice;

        switch (choice){
    case 1: sortFlightsByNumber(flights, flightCount);
        break;

    case 2: sortFlightsByDestination(flights, flightCount);
        break;

    case 3: sortFlightsByDate(flights, flightCount);
        break;
    
    default: cout << "Invalid choice. (enter a number 1-3)\n";
        
        }
    }

void sortFlightsByNumber(Flight flights[], int flightCount){

        if (flightCount == 0)
        {
            cout << "No flights available.\n";
            return;
        }

        for (int i = 0; i < flightCount - 1; i++)
        {
            for (int j = 0;
                j < flightCount - i - 1;
                j++)
            {
                if (flights[j].number >
                    flights[j + 1].number)
                {
                    Flight temp = flights[j];

                    flights[j] = flights[j + 1];

                    flights[j + 1] = temp;
                }
            }
    
    }   

        cout << "Flights sorted by number.\n";
    }

void sortFlightsByDestination(Flight flights[], int flightCount){
        if (flightCount == 0)
        {
            cout << "No flights available.\n";
            return;
        }

        for (int i = 0; i < flightCount - 1; i++)
        {
            for (int j = 0;
                j < flightCount - i - 1;
                j++)
            {
                if (strcmp(flights[j].destination,
                    flights[j + 1].destination) > 0)
                {
                    Flight temp = flights[j];

                    flights[j] = flights[j + 1];

                    flights[j + 1] = temp;
                }
            }
    }
    
        cout << "Flights sorted by destination.\n";
}


void sortFlightsByDate(Flight flights[],
    int flightCount){
        if (flightCount == 0)
        {
            cout << "No flights available.\n";
            return;
        }

        for (int i = 0; i < flightCount - 1; i++)
        {
            for (int j = 0;
                j < flightCount - i - 1;
                j++)
            {
                if (
    flights[j].departureDate.year >
        flights[j + 1].departureDate.year ||

    (flights[j].departureDate.year ==
        flights[j + 1].departureDate.year &&

     flights[j].departureDate.month >
        flights[j + 1].departureDate.month) ||

    (flights[j].departureDate.year ==
        flights[j + 1].departureDate.year &&

     flights[j].departureDate.month ==
        flights[j + 1].departureDate.month &&

     flights[j].departureDate.day >
        flights[j + 1].departureDate.day)
)
                {
                    Flight temp = flights[j];

                    flights[j] = flights[j + 1];

                    flights[j + 1] = temp;
                }
            }
    }
    
        cout << "Flights sorted by date.\n";
    }


void deleteFlight(Flight flights[], int& flightCount,
     Passenger passengers[], int& passengerCount){
    int choice;

    cout << "\n=== DELETE FLIGHTS ===\n";

    cout << "1 Delete by number\n";
    cout << "2 Delete by destination\n";
    cout << "3 Delete by date\n";

    cout << "Choose: ";
    cin >> choice;

    if (choice == 1)
    {
        deleteFlightbyNumber(flights, flightCount, passengers, passengerCount);
    }
    else if (choice == 2)
    {
        deleteFlightbyDestination(flights, flightCount, passengers, passengerCount);
    }
    else if (choice == 3)
    {
        deleteFlightbyDate(flights, flightCount, passengers, passengerCount);
    }
    else
    {
        cout << "Invalid choice.\n";
    }
    }

    void deleteFlightbyNumber(Flight flights[], int& flightCount,
         Passenger passengers[], int& passengerCount){
        int number;
        bool found = false;

        cout << "Enter flight number: ";
        cin >> number;

        for (int i = 0; i < flightCount; i++)
        {
            if (flights[i].number == number)
            {
                cascadeDeletePassengersOnFlight(passengers, passengerCount, number);

                for (int j = i;
                    j < flightCount - 1;
                    j++)
                {
                    flights[j] =
                        flights[j + 1];
                }

                flightCount--;

                found = true;

                cout << "Flight deleted.\n";
                cout << "Associated passengers removed.\n";

                showFlights(flights, flightCount);

                break;
            }
        }

        if (!found)
        {
            cout << "Flight not found.\n";
        }
    }

    void deleteFlightbyDestination(Flight flights[], int& flightCount,
         Passenger passengers[], int& passengerCount){
        char destination[30];
        bool found = false;

        cout << "Enter destination: ";
        cin >> destination;

        for (int i = 0; i < flightCount; i++)
        {
            if (strcmp(flights[i].destination,
                destination) == 0)
            {
                cascadeDeletePassengersOnFlight(passengers, passengerCount, flights[i].number);

                for (int j = i;
                    j < flightCount - 1;
                    j++)
                {
                    flights[j] =
                        flights[j + 1];
                }

                flightCount--;

                found = true;

                cout << "Flight deleted.\n";
                cout << "Associated passengers removed.\n";

                showFlights(flights, flightCount);

                break;
            }
        }

        if (!found)
        {
            cout << "No flights found.\n";
        }
    }

    void deleteFlightbyDate(Flight flights[], int& flightCount,
         Passenger passengers[], int& passengerCount){
        int d, m, y;
        bool found = false;

        cout << "Enter date (day month year): ";
        cin >> d >> m >> y;

        for (int i = 0; i < flightCount; i++)
        {
            if (flights[i].departureDate.day == d &&
                flights[i].departureDate.month == m &&
                flights[i].departureDate.year == y)
            {
                cascadeDeletePassengersOnFlight(passengers, passengerCount, flights[i].number);

                for (int j = i;
                    j < flightCount - 1;
                    j++)
                {
                    flights[j] =
                        flights[j + 1];
                }

                flightCount--;

                found = true;

                cout << "Flight deleted.\n";
                cout << "Associated passengers removed.\n";

                showFlights(flights, flightCount);

                break;
            }
        }

        if (!found)
        {
            cout << "No flights found.\n";
        }
    }

    

void flightsMenu(Flight flights[], int& flightCount,
     Plane planes[], int planeCount,
     Passenger passengers[], int& passengerCount)
{
    int choice;

    do
    {
        

    cout << "\n=== FLIGHTS ===\n";

    cout << "1 Add flight\n";
    cout << "2 Show flights\n";
    cout << "3 Edit flight\n";
    cout << "4 Search flight\n";
    cout << "5 Sort flights\n";
    cout << "6 Delete flight\n";
    cout << "7 Back to main menu\n";

    cout << "Choose: ";
    cin >> choice;



    if (choice == 1)
    {
        if (flightCount >= MAX_FLIGHTS)
        {
            cout << "Flight limit reached.\n";
            return;
        }

        addFlight(flights, flightCount, planes, planeCount);
    }



    else if (choice == 2)
    {
        if (flightCount == 0)
        {
            cout << "No flights available.\n";
            return;
        }

        showFlights(flights, flightCount);
    }



    else if (choice == 3)
    {
        editFlight(flights, flightCount);
    }



    else if (choice == 4)
    {
        searchFlights(flights, flightCount);
    }



    else if (choice == 5)
    {
        sortFlights(flights, flightCount);
    }


    else if (choice == 6)
    {
        deleteFlight(flights, flightCount, passengers, passengerCount);
    }

else if (choice == 7)
    {
        return;
    }

else if (choice != 7)
    {
        cout << "Invalid choice.\n";
    }

}while (choice != 7);
}