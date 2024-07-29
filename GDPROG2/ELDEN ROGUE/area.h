#pragma once

#include "structures.h"
#include "character_creation.h"
#include "title.h"

void runArea(Area* pArea, Array sCoordinate, Player* pPlayer, int nShard);
void areaScreen(char* strAreaName);
void printFloor(Area* pArea, Array sCoordinate);
void processInput(char cInput, Area* pArea, Array sCoordinate, Player* pPlayer, int nShard);
void floorPass(Player* pPlayer, Area* pArea, int* pPlayerLocation, int nShard);
void initializeArea(int nRow, int nColumn, int nRowOffset, Area* pArea, int* pTemp);
void areaSelect(char cAreaIndex, char cFastTravelTile, Player* pPlayer);
