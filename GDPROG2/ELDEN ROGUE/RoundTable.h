#pragma once
#include "structures.h"
#include "character_creation.h"
#include "title.h"
#include "shop.h"

void runRoundTable(Player* player);
void displayRoundTable(Player* player);
int runemath(Player* player);
void processlevelup(Player* player);

void processInventory(Player* player);
void processInputs(Player* player, char cInput);
void processFastTravel(Player* pPlayer);

