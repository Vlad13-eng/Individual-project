#include "passenger.h"
#include "airport.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// ============ VALIDATION FUNCTIONS ============

bool isFlightExist(Flight flights[], int flightCount, int flightNumber)
{
    for (int i = 0; i < flightCount; i++)
    {
        if (flights[i].number == flightNumber)
        {
            return true;
        }
    }
    return false;
}

bool isSeatOverbooking(Passenger passengers[], int passengerCount, int flightNumber, int seat)
{
    for (int i = 0; i < passengerCount; i++)
    {
        if (passengers[i].flightNumber == flightNumber &&
            passengers[i].seat == seat)
        {
            return true;
        }
    }
    return false;
}

// ============ MAIN FUNCTIONS ============

void addPassenger(Passenger passengers[], int& passengerCount,
     Flight flights[], int flightCount){

        cout << "Code: ";
        cin >> passengers[passengerCount].code;
        for (int i = 0; i < passengerCount; i++)
{
    if (passengers[i].code ==
        passengers[passengerCount].code)
    {
        cout << "Passenger code already exists.\n";
        return;
    }
}

        cout << "Surname: ";
        cin >> passengers[passengerCount].surname;

        cout << "Name: ";
        cin >> passengers[passengerCount].name;

        cout << "Flight number: ";
        cin >> passengers[passengerCount].flightNumber;

        // Validate flight exists
        if (!isFlightExist(flights, flightCount, passengers[passengerCount].flightNumber))
        {
            cout << "Flight does not exist.\n";
            cout << "Passenger not added.\n";
            return;
        }

        cout << "Seat: ";
        cin >> passengers[passengerCount].seat;

        if (passengers[passengerCount].seat <= 0)
{
    cout << "Invalid seat number.\n";
    return;
}

        // Prevent overbooking - check if seat already taken on this flight
        if (isSeatOverbooking(passengers, passengerCount, 
                              passengers[passengerCount].flightNumber,
                              passengers[passengerCount].seat))
        {
            cout << "Seat already taken on this flight.\n";
            cout << "Passenger not added.\n";
            return;
        }

        passengerCount++;

        cout << "Passenger added successfully.\n";

        showPassengers(passengers, passengerCount);
}

void showPassengers(Passenger passengers[], int passengerCount)
{
    if (passengerCount == 0)
    {
        cout << "No passengers available.\n";
        return;
    }

    cout << "\n====================== PASSENGERS ======================\n";

    cout << left
         << setw(8)  << "Code"
         << setw(15) << "Surname"
         << setw(15) << "Name"
         << setw(12) << "Flight"
         << setw(6)  << "Seat"
         << endl;

    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < passengerCount; i++)
    {
        cout << left
             << setw(8)  << passengers[i].code
             << setw(15) << passengers[i].surname
             << setw(15) << passengers[i].name
             << setw(12) << passengers[i].flightNumber
             << setw(6)  << passengers[i].seat
             << endl;
    }
}

void editPassenger(Passenger passengers[], int passengerCount){
    int code;
        bool found = false;

        cout << "Enter Code: ";
        cin >> code;

        for (int i = 0; i < passengerCount; i++)
        {
            if (passengers[i].code == code)
            {
                cout << "New Name: ";
                cin >> passengers[i].name;

                cout << "New Surname: ";
                cin >> passengers[i].surname;

                found = true;

                cout << "Passenger updated.\n";
            }
        }

        if (!found)
        {
            cout << "Passenger not found.\n";
        }
        showPassengers(passengers, passengerCount);
}

void deletePassenger(Passenger passengers[], int& passengerCount){
    int choice;

    cout << "\n=== DELETE PASSENGERS ===\n";

cout << "1 Delete by code\n";
cout << "2 Delete by surname\n";
cout << "3 Delete by flight\n";
cout << "4 Back to main menu\n";

    cout << "Choose: ";
    cin >> choice;

    if (choice == 1)
    {
        deletePassengerByCode(passengers, passengerCount);
    }
    else if (choice == 2)
    {
        deletePassengerBySurname(passengers, passengerCount);
    }
    else if (choice == 3)
    {
        deletePassengerByFlight(passengers, passengerCount);
    }
    else if (choice == 4)
    {
        return;
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

void deletePassengerByCode(Passenger passengers[], int& passengerCount){
    int code;
        bool found = false;

        cout << "Enter Code: ";
        cin >> code;

        for (int i = 0; i < passengerCount; i++)
        {
            if (passengers[i].code == code)
            {
                for (int j = i;
                    j < passengerCount - 1;
                    j++)
                {
                    passengers[j] =
                        passengers[j + 1];
                }

                passengerCount--;

                found = true;

                cout << "Passenger deleted.\n";

                break;
            }
        }

        if (!found)
        {
            cout << "Passenger not found.\n";
        }
        showPassengers(passengers, passengerCount);
}

void deletePassengerBySurname(Passenger passengers[], int& passengerCount){
    char surname[30];
        bool found = false;

        cout << "Enter surname: ";
        cin >> surname;

        for (int i = 0; i < passengerCount; i++)
        {
            if (strcmp(passengers[i].surname,
                surname) == 0)
            {
                for (int j = i;
                    j < passengerCount - 1;
                    j++)
                {
                    passengers[j] =
                        passengers[j + 1];
                }

                passengerCount--;

                found = true;

                cout << "Passenger deleted.\n";

                break;
            }
        }

        if (!found)
        {
            cout << "Passenger not found.\n";
        }
        showPassengers(passengers, passengerCount);
}

void deletePassengerByFlight(Passenger passengers[], int& passengerCount){
    int flight;
        bool found = false;

        cout << "Enter flight: ";
        cin >> flight;

        for (int i = 0; i < passengerCount; i++)
        {
            if (passengers[i].flightNumber ==
                flight)
            {
                for (int j = i;
                    j < passengerCount - 1;
                    j++)
                {
                    passengers[j] =
                        passengers[j + 1];
                }

                passengerCount--;

                found = true;

                cout << "Passenger deleted.\n";

                break;
            }
        }

        if (!found)
        {
            cout << "No passengers found.\n";
        }
        showPassengers(passengers, passengerCount);
    }

    void searchPassenger(Passenger passengers[], int passengerCount){
        int choice;

        cout << "\n=== SEARCH PASSENGERS ===\n";

        cout << "1 Search by code\n";
        cout << "2 Search by surname\n";
        cout << "3 Search by flight\n";
        cout << "4 Back to main menu\n";

        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            searchPassengerByCode(passengers, passengerCount);
        }
        else if (choice == 2)
        {
            searchPassengerBySurname(passengers, passengerCount);
        }
        else if (choice == 3)
        {
            searchPassengerByFlight(passengers, passengerCount);
        }
        else if (choice == 4)
        {
            return;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    void searchPassengerByCode(Passenger passengers[], int passengerCount){
        int code;
        bool found = false;
        int foundIndex = -1;

        cout << "Enter Code: ";
        cin >> code;

                        cout << left
     << setw(8)  << "ID"
     << setw(15) << "Name"
     << setw(18) << "Surname"
     << setw(10) << "Flight"
     << setw(6)  << "Seat"
     << endl;


        for (int i = 0; i < passengerCount; i++)
        {
            if (passengers[i].code == code)
            {

cout << "--------------------------------------------------------\n";

cout << left
     << setw(8)  << passengers[i].code
     << setw(15) << passengers[i].name
     << setw(18) << passengers[i].surname
     << setw(10) << passengers[i].flightNumber
     << setw(6)  << passengers[i].seat
     << endl;


                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "Passenger not found.\n";
        }
        else
        {
            char response;
            cout << "Delete this passenger? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < passengerCount - 1;
                    j++)
                {
                    passengers[j] = passengers[j + 1];
                }

                passengerCount--;
                cout << "Passenger deleted.\n";
            }
        }
    }

    void searchPassengerBySurname(Passenger passengers[], int passengerCount){
        char surname[30];
        bool found = false;
        int foundIndex = -1;

        cout << "Enter surname: ";
        cin >> surname;

                        cout << left
     << setw(8)  << "ID"
     << setw(15) << "Name"
     << setw(18) << "Surname"
     << setw(10) << "Flight"
     << setw(6)  << "Seat"
     << endl;

cout << "--------------------------------------------------------\n";


        for (int i = 0; i < passengerCount; i++)
        {
            if (strcmp(passengers[i].surname,
                surname) == 0)
            {

cout << left
     << setw(8)  << passengers[i].code
     << setw(15) << passengers[i].name
     << setw(18) << passengers[i].surname
     << setw(10) << passengers[i].flightNumber
     << setw(6)  << passengers[i].seat
     << endl;


                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "Passenger not found.\n";
        }
        else
        {
            char response;
            cout << "Delete this passenger? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < passengerCount - 1;
                    j++)
                {
                    passengers[j] = passengers[j + 1];
                }

                passengerCount--;
                cout << "Passenger deleted.\n";
            }
        }
    }

    void searchPassengerByFlight(Passenger passengers[], int passengerCount){
        int flight;
        bool found = false;
        int foundIndex = -1;

        cout << "Enter flight: ";
        cin >> flight;

                        cout << left
     << setw(8)  << "ID"
     << setw(15) << "Name"
     << setw(18) << "Surname"
     << setw(10) << "Flight"
     << setw(6)  << "Seat"
     << endl;

     cout << "---------------------------------------------------------\n";

        for (int i = 0; i < passengerCount; i++)
        {
            if (passengers[i].flightNumber ==
                flight)
            {

cout << left
     << setw(8)  << passengers[i].code
     << setw(15) << passengers[i].name
     << setw(18) << passengers[i].surname
     << setw(10) << passengers[i].flightNumber
     << setw(6)  << passengers[i].seat
     << endl;

                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "No passengers found.\n";
        }
        else
        {
            char response;
            cout << "Delete this passenger? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < passengerCount - 1;
                    j++)
                {
                    passengers[j] = passengers[j + 1];
                }

                passengerCount--;
                cout << "Passenger deleted.\n";
            }
        }
    }

    void sortPassengers(Passenger passengers[], int passengerCount){
        int choice;

        cout << "\n=== SORT PASSENGERS ===\n";

        cout << "1 Sort by code\n";
        cout << "2 Sort by surname\n";
        cout << "3 Sort by flight\n";
        cout << "4 Back to main menu\n";

        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            sortPassengersByCode(passengers, passengerCount);
        }
        else if (choice == 2)
        {
            sortPassengersBySurname(passengers, passengerCount);
        }
        else if (choice == 3)
        {
            sortPassengersByFlight(passengers, passengerCount);
        }
        else if (choice == 4)
        {
            return;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
    
    void sortPassengersByCode(Passenger passengers[], int passengerCount){
        if (passengerCount == 0)
        {
            cout << "No passengers available.\n";
            return;
        }

        for (int i = 0; i < passengerCount - 1; i++)
        {
            for (int j = 0;
                j < passengerCount - i - 1;
                j++)
            {
                if (passengers[j].code >
                    passengers[j + 1].code)
                {
                    Passenger temp = passengers[j];

                    passengers[j] = passengers[j + 1];

                    passengers[j + 1] = temp;
                }
            }
        }

        cout << "Passengers sorted by code.\n";
    }

    void sortPassengersBySurname(Passenger passengers[], int passengerCount){
        if (passengerCount == 0)
        {
            cout << "No passengers available.\n";
            return;
        }

        for (int i = 0; i < passengerCount - 1; i++)
        {
            for (int j = 0;
                j < passengerCount - i - 1;
                j++)
            {
                if (strcmp(passengers[j].surname,
                    passengers[j + 1].surname) > 0)
                {
                    Passenger temp = passengers[j];

                    passengers[j] = passengers[j + 1];

                    passengers[j + 1] = temp;
                }
            }
        }

        cout << "Passengers sorted by surname.\n";
    }

    void sortPassengersByFlight(Passenger passengers[], int passengerCount){
        if (passengerCount == 0)
        {
            cout << "No passengers available.\n";
            return;
        }

        for (int i = 0; i < passengerCount - 1; i++)
        {
            for (int j = 0;
                j < passengerCount - i - 1;
                j++)
            {
                if (passengers[j].flightNumber >
                    passengers[j + 1].flightNumber)
                {
                    Passenger temp = passengers[j];

                    passengers[j] = passengers[j + 1];

                    passengers[j + 1] = temp;
                }
            }
        }

        cout << "Passengers sorted by flight number.\n";
    }

void passengerMenu(Passenger passengers[], int& passengerCount,
     Flight flights[], int flightCount)
{
    int choice;

    do
    {
    cout << "\n=== PASSENGERS ===\n";

    cout << "1 Add passenger\n";
    cout << "2 Show passengers\n";
    cout << "3 Edit passenger\n";
    cout << "4 Delete passenger\n";
    cout << "5 Search passenger\n";
    cout << "6 Sort passengers\n";
    cout << "7 Back to main menu\n";

    cout << "Choose: ";
    cin >> choice;



    if (choice == 1)
    {
        if (passengerCount >= MAX_PASSENGERS)
        {
            cout << "Passenger limit reached.\n";
            return;
        }

        addPassenger(passengers, passengerCount, flights, flightCount);
    }



    else if (choice == 2)
    {
        showPassengers(passengers, passengerCount);
    }



    else if (choice == 3)
    {
        editPassenger(passengers, passengerCount);
    }



    else if (choice == 4)
    {
        deletePassenger(passengers, passengerCount);
    }



    else if (choice == 5)
    {
        searchPassenger(passengers, passengerCount);
    }



    else if (choice == 6)
    {
        sortPassengers(passengers, passengerCount);
    }

    else if (choice == 7){
        return;
    }

    else if (choice != 7)
    {
        cout << "Invalid choice.\n";
    }
}while (choice != 7);
}