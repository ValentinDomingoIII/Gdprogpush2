#pragma once

#include "structures.h"

void runStormveil(int* pFloor, int* pFlag, Stormveil* sArea, int nRow, int nColumn);
// void initializeFloor(int* pTemp, int nSize, Stormveil* sFloor, int nRow, int nColumn);
void printFloor(int* pFloor, int nRow, int nColumn);
void processInput(char cInput, int* pFloor, int nRow, int nColumn, int nFloorCount, int* pPlayerLocation, int* pRunes);
void initializeStormveil();