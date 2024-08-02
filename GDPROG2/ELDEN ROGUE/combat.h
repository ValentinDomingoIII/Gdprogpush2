#pragma once

#include "color.h"
#include "stddef.h"
#include "string.h"

#include "structures.h"
#include "definitions.h"

void runCombat(Player* pPlayer, Area* pArea, int* pMaxHealth, int nFloorType, int* pShard);
void playerTurn(int* pTurn, int* pDodge, int* pPlayerMove, int* pMaxHealth, int nFloorType, Enemy* pEnemy, Area* pArea, Player* pPlayer);
void initializeEnemy(Enemy* pEnemy, Area* pArea, int nRandom);
int processAttack(char cInput, Player* pPlayer, Enemy* pEnemy);
void enemyTurn(int nDodge, int* pPlayerMove, int* pMaxHealth, Enemy sEnemy, Player* pPlayer);
void initializeBoss(Enemy* pEnemy, Area* pArea);
void printTurn(int nTurnType, Enemy* pEnemy, Player *pPlayer, int nTempMaxHealth, int nMaxHealth);
