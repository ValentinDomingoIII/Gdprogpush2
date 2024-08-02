#pragma once

#include "title.h"
#include "round_table.h"
#include "area.h"
#include "files.h"

void runCharCreation(Player* player);
void printCharCreationScreen();
int processCharInputs(char cChoice, Player* player);
void runNameInput(Player* player);
void runJobClassInput(Player* player);
void displayCurrentCharacter(Player* player);
void setJobClass(Player* player, int jobClass);

