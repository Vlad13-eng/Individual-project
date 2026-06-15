#include "planes.h"
#include "airport.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void addPlane(Plane planes[], int& planeCount)
{
    if (planeCount >= MAX_PLANES)
    {
        cout << "Plane limit reached.\n";
        return;
    }

    cout << "Plane ID: ";
    cin >> planes[planeCount].id;

    for (int i = 0; i < planeCount; i++)
{
    if (planes[i].id == planes[planeCount].id)
    {
        cout << "Plane ID already exists.\n";
        return;
    }
}

    cout << "Model: ";
    cin >> planes[planeCount].model;

    cout << "Manufacturer: ";
    cin >> planes[planeCount].manufacturer;

    cout << "Capacity: ";
    cin >> planes[planeCount].capacity;

    if (planes[planeCount].capacity <= 0)
{
    cout << "Invalid capacity.\n";
    return;
}

    planeCount++;

    cout << "Plane added successfully.\n";

    showPlanes(planes, planeCount);
}

void showPlanes(Plane planes[], int planeCount)
{
    if (planeCount == 0)
    {
        cout << "No planes available.\n";
        return;
    }

    cout << "\n========================= PLANES =========================\n";

    cout << left
         << setw(8)  << "ID"
         << setw(20) << "Model"
         << setw(20) << "Manufacturer"
         << setw(12) << "Capacity"
         << endl;

    cout << "----------------------------------------------------------\n";

    for (int i = 0; i < planeCount; i++)
    {
        cout << left
             << setw(8)  << planes[i].id
             << setw(20) << planes[i].model
             << setw(20) << planes[i].manufacturer
             << setw(12) << planes[i].capacity
             << endl;
    }
}

void editPlane(Plane planes[],
    int planeCount)
{
    int id;
    bool found = false;

    cout << "Enter plane ID: ";
    cin >> id;

    for (int i = 0; i < planeCount; i++)
    {
        if (planes[i].id == id)
        {
            cout << "New model: ";
            cin >> planes[i].model;

            cout << "New manufacturer: ";
            cin >> planes[i].manufacturer;

            cout << "New capacity: ";
            cin >> planes[i].capacity;

                if (planes[i].capacity <= 0)
{
    cout << "Invalid capacity.\n";
    return;
}

            found = true;

            cout << "Plane updated.\n";
            showPlanes(planes, planeCount);
        }
    }

    if (!found)
    {
        cout << "Plane not found.\n";
    }
}

void searchPlanes(Plane planes[],
    int planeCount)
{
    int choice;

    cout << "\n=== SEARCH PLANES ===\n";

    cout << "1 Search by ID\n";
    cout << "2 Search by model\n";
    cout << "3 Search by manufacturer\n";

    cout << "Choose: ";
    cin >> choice;



    if (choice == 1)
    {
        searchPlanesById(planes, planeCount);
    }



    else if (choice == 2)
    {
        searchPlanesByModel(planes, planeCount);
    }



    else if (choice == 3)
    {
        searchPlanesByManufacturer(planes,planeCount);
    }

    else
    {
        cout << "Invalid choice.\n";
    }
}

void searchPlanesById(Plane planes[], int planeCount){
        int id;
        bool found = false;
        int foundIndex = -1;

        cout << "Enter plane ID: ";
        cin >> id;

        cout << left
     << setw(8)  << "ID"
     << setw(20) << "Model"
     << setw(20) << "Manufacturer"
     << setw(12) << "Capacity"
     << endl;

cout << "----------------------------------------------------------\n";

        for (int i = 0; i < planeCount; i++)
        {
            if (planes[i].id == id)
            {

cout << left
     << setw(8)  << planes[i].id
     << setw(20) << planes[i].model
     << setw(20) << planes[i].manufacturer
     << setw(12) << planes[i].capacity
     << endl;

                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "Plane not found.\n";
        }
        else
        {
            char response;
            cout << "Delete this plane? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < planeCount - 1;
                    j++)
                {
                    planes[j] = planes[j + 1];
                }

                planeCount--;
                cout << "Plane deleted.\n";
            }
        }
    }

    void searchPlanesByModel(Plane planes[], int planeCount){
        char model[30];
        bool found = false;
        int foundIndex = -1;

        cout << "Enter model: ";
        cin >> model;

                        cout << left
     << setw(8)  << "ID"
     << setw(20) << "Model"
     << setw(20) << "Manufacturer"
     << setw(12) << "Capacity"
     << endl;

cout << "----------------------------------------------------------\n";

        for (int i = 0; i < planeCount; i++)
        {
            if (strcmp(planes[i].model,
                model) == 0)
            {

cout << left
     << setw(8)  << planes[i].id
     << setw(20) << planes[i].model
     << setw(20) << planes[i].manufacturer
     << setw(12) << planes[i].capacity
     << endl;


                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "No planes found.\n";
        }
        else
        {
            char response;
            cout << "Delete this plane? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < planeCount - 1;
                    j++)
                {
                    planes[j] = planes[j + 1];
                }

                planeCount--;
                cout << "Plane deleted.\n";
            }
        }
    }

    void searchPlanesByManufacturer(Plane planes[], int planeCount){
                char manufacturer[30];
        bool found = false;
        int foundIndex = -1;

        cout << "Enter manufacturer: ";
        cin >> manufacturer;

                        cout << left
     << setw(8)  << "ID"
     << setw(20) << "Model"
     << setw(20) << "Manufacturer"
     << setw(12) << "Capacity"
     << endl;

cout << "----------------------------------------------------------\n";

        for (int i = 0; i < planeCount; i++)
        {
            if (strcmp(planes[i].manufacturer,
                manufacturer) == 0)
            {

cout << left
     << setw(8)  << planes[i].id
     << setw(20) << planes[i].model
     << setw(20) << planes[i].manufacturer
     << setw(12) << planes[i].capacity
     << endl;

                found = true;
                foundIndex = i;
            }
        }

        if (!found)
        {
            cout << "No planes found.\n";
        }
        else
        {
            char response;
            cout << "Delete this plane? (Y/N): ";
            cin >> response;

            if (response == 'Y' || response == 'y')
            {
                for (int j = foundIndex;
                    j < planeCount - 1;
                    j++)
                {
                    planes[j] = planes[j + 1];
                }

                planeCount--;
                cout << "Plane deleted.\n";
            }
        }
    }
    

void sortPlanes(Plane planes[],
    int planeCount)
{
    int choice;

    cout << "\n=== SORT PLANES ===\n";
    cout << "1 Sort by ID\n";
    cout << "2 Sort by model\n";
    cout << "3 Sort by manufacturer\n";

    cout << "Choose: ";
    cin >> choice;

    if (choice == 1)
    {
        sortPlanesById(planes, planeCount);
    }
    else if (choice == 2)
    {
        sortPlanesByModel(planes, planeCount);
    }
    else if (choice == 3)
    {
        sortPlanesByManufacturer(planes, planeCount);
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

void sortPlanesById(Plane planes[], int planeCount){
    for (int i = 0; i < planeCount - 1; i++)
    {
        for (int j = 0;
            j < planeCount - i - 1;
            j++)
        {
            if (planes[j].id >
                planes[j + 1].id)
            {
                Plane temp = planes[j];

                planes[j] = planes[j + 1];

                planes[j + 1] = temp;
            }
        }
    }

    cout << "Planes sorted by ID.\n";
}

void sortPlanesByModel(Plane planes[], int planeCount){
    for (int i = 0; i < planeCount - 1; i++)
    {
        for (int j = 0;
            j < planeCount - i - 1;
            j++)
        {
            if (strcmp(planes[j].model, planes[j + 1].model) > 0)
            {
                Plane temp = planes[j];

                planes[j] = planes[j + 1];

                planes[j + 1] = temp;
            }
        }
    }

    cout << "Planes sorted by model.\n";
}

void sortPlanesByManufacturer(Plane planes[], int planeCount){
    for (int i = 0; i < planeCount - 1; i++)
    {
        for (int j = 0;
            j < planeCount - i - 1;
            j++)
        {
            if (strcmp(planes[j].manufacturer, planes[j + 1].manufacturer) > 0)
            {
                Plane temp = planes[j];

                planes[j] = planes[j + 1];

                planes[j + 1] = temp;
            }
        }
    }

    cout << "Planes sorted by manufacturer.\n";
}

void deletePlane(Plane planes[], int& planeCount)
{
    int choice;
    cout << "\n=== DELETE PLANE ===\n";
    cout << "1 Delete by ID\n";
    cout << "2 Delete by model\n";
    cout << "3 Delete by manufacturer\n";

    cout << "Choose: ";
    cin >> choice;

    if (choice == 1){
        deletePlaneById(planes, planeCount);
    }
    else if (choice == 2)
    {
        deletePlaneByModel(planes, planeCount);
    }
    else if (choice == 3)
    {
        deletePlaneByManufacturer(planes, planeCount);
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

void deletePlaneById(Plane planes[], int& planeCount){
    int id;
        bool found = false;

        cout << "Enter plane ID: ";
        cin >> id;

        for (int i = 0; i < planeCount; i++)
        {
            if (planes[i].id == id)
            {
                for (int j = i;
                    j < planeCount - 1;
                    j++)
                {
                    planes[j] =
                        planes[j + 1];
                }

                planeCount--;

                found = true;

                cout << "Plane deleted.\n";

                showPlanes(planes, planeCount);

                break;
            }
        }


        if (!found)
        {
            cout << "Plane not found.\n";
        }
    }

    void deletePlaneByModel(Plane planes[], int& planeCount){
        char model[30];
        bool found = false;

        cout << "Enter model: ";
        cin >> model;

        for (int i = 0; i < planeCount; i++)
        {
            if (strcmp(planes[i].model,
                model) == 0)
            {
                for (int j = i;
                    j < planeCount - 1;
                    j++)
                {
                    planes[j] =
                        planes[j + 1];
                }

                planeCount--;

                found = true;

                cout << "Plane deleted.\n";

                showPlanes(planes, planeCount);

                break;
            }
        }

        if (!found)
        {
            cout << "No planes found.\n";
        }
    }

    void deletePlaneByManufacturer(Plane planes[], int& planeCount){
        char manufacturer[30];
        bool found = false;

        cout << "Enter manufacturer: ";
        cin >> manufacturer;

        for (int i = 0; i < planeCount; i++)
        {
            if (strcmp(planes[i].manufacturer,
                manufacturer) == 0)
            {
                for (int j = i;
                    j < planeCount - 1;
                    j++)
                {
                    planes[j] =
                        planes[j + 1];
                }

                planeCount--;

                found = true;

                cout << "Plane deleted.\n";

                showPlanes(planes, planeCount);

                break;
            }
        }

        if (!found)
        {
            cout << "No planes found.\n";
        }
    }

void planesMenu(Plane planes[],
    int& planeCount)
{
    int choice;

    do{

    cout << "\n=== PLANES ===\n";

    cout << "1 Add plane\n";
    cout << "2 Show planes\n";
    cout << "3 Edit plane\n";
    cout << "4 Search planes\n";
    cout << "5 Sort planes\n";
    cout << "6 Delete plane\n";
    cout << "7 Back to main menu\n";

    cout << "Choose: ";
    cin >> choice;



    if (choice == 1)
    {
        if (planeCount >= MAX_PLANES)
        {
            cout << "Plane limit reached.\n";
            return;
        }
        addPlane(planes, planeCount);
    }



    else if (choice == 2)
    {
        showPlanes(planes, planeCount);
    }



    else if (choice == 3)
    {
        editPlane(planes, planeCount);
    }



    else if (choice == 4)
    {
        searchPlanes(planes, planeCount);
    }



    else if (choice == 5)
    {
        sortPlanes(planes, planeCount);
    }



    else if (choice == 6)
    {
        deletePlane(planes, planeCount);
    }

    else if (choice != 7)
    {
        cout << "Invalid choice.\n";
    }

}while(choice != 7);
    return;
}