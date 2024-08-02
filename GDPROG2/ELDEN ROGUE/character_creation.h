#pragma once

#include "title.h"
#include "round_table.h"
#include "area.h"
#include "files.h"

void runCharCreation(Player* pPlayer);
void printCharCreationScreen();
int processCharInputs(char cChoice, Player* pPlayer);
void runNameInput(Player* pPlayer);
void runJobClassInput(Player* pPlayer);
void displayCurrentCharacter(Player* pPlayer);
void setJobClass(Player* pPlayer, int jobClass);

