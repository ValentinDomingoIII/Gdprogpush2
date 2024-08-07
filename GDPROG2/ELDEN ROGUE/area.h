#pragma once

#include "string.h"
#include "structures.h"
#include "definitions.h"
#include "combat.h"
#include "color.h"
#include "round_table.h"

void runArea(Area* pArea, Array sCoordinate, Player* pPlayer, int* pShard, int* pMaxHealth);
void areaScreen(char* strAreaName);
void printFloor(Area* pArea, Array sCoordinate);
void processInput(char cInput, Area* pArea, Array sCoordinate, Player* pPlayer, int* pShard, int* pMaxHealth) ;
void floorPass(Player* pPlayer, Area* pArea, int* pShard);
void findDoor(Player* pPlayer, Area* pArea, Array sCoordinate, int nValue);
void initializeArea(int nRow, int nColumn, int nRowOffset, Area* pArea, int* pTemp);
void areaSelect(char cAreaIndex, char cFastTravelTile, Player* pPlayer);
void runCredits();

