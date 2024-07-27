#pragma once

void runCombat(Player* pPlayer);
void printCombatScreen(Player* pPlayer);
void printOption(int* pPlayerOptions);
void assessOption(int nX);
void processOption(char cInput, int* pPlayerOptions, int nSize, int* nTurn);

