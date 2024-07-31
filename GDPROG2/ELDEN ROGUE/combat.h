#pragma once

#include "color.h"
#include "stddef.h"

#include "structures.h"
#include "definitions.h"

void runCombat(Player* pPlayer, Area* pArea, int* pMaxHealth);
void playerTurn(int* pDodge, int* pPlayerMove, int* pMaxHealth, Enemy* pEnemy, Area* pArea, Player* pPlayer);
void initializeEnemy(Enemy* pEnemy, Area* pArea, int nRandom);
int processAttack(char cInput, Player* pPlayer, Enemy* pEnemy);
void enemyTurn(int nDodge, int* pPlayerMove, int* pMaxHealth, Enemy sEnemy);



