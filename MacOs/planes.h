#ifndef PLANES_H
#define PLANES_H

#include "airport.h"

void planesMenu(Plane planes[], int& planeCount);

void addPlane(Plane planes[], int& planeCount);
void showPlanes(Plane planes[], int planeCount);
void editPlane(Plane planes[], int planeCount);

void searchPlanes(Plane planes[], int planeCount);
void deletePlane(Plane planes[], int& planeCount);
void sortPlanes(Plane planes[], int planeCount);

void searchPlanesById(Plane planes[], int planeCount);
void searchPlanesByModel(Plane planes[], int planeCount);
void searchPlanesByManufacturer(Plane planes[], int planeCount);

void deletePlaneById(Plane planes[], int& planeCount);
void deletePlaneByModel(Plane planes[], int& planeCount);
void deletePlaneByManufacturer(Plane planes[], int& planeCount);

void sortPlanesById(Plane planes[], int planeCount);
void sortPlanesByModel(Plane planes[], int planeCount);
void sortPlanesByManufacturer(Plane planes[], int planeCount);

#endif