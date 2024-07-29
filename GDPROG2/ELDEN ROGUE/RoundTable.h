#pragma once

#include "character_creation.h"
#include "title.h"
#include "structures.h"

void runRoundTable(Player* player);
void displayRoundTable(Player* player);
int runemath(Player* player);
void processlevelup(Player* player);
void BuySwords(Player* player);
void processShop(Player* player);
void processInputs(Player* player, char cInput);
void processFastTravel(Player* pPlayer);

