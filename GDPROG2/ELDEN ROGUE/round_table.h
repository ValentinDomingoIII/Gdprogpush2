#pragma once

#include "structures.h"
#include "character_creation.h"
#include "title.h"
#include "shop.h"
#include "stddef.h"
#include "files.h"
#include "level.h"
#include "inventory.h"

void runRoundTable(Player* player);
void displayRoundTable(Player* player);
int runemath(Player* player);

void processInputs(Player* player, char cInput);
void processFastTravel(Player* pPlayer);
