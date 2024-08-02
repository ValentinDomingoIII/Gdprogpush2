#pragma once

#include "structures.h"
#include "character_creation.h"
#include "title.h"
#include "shop.h"
#include "stddef.h"
#include "files.h"
#include "level.h"
#include "inventory.h"

void runRoundTable(Player* pPlayer);
void displayRoundTable(Player* pPlayer);
int runemath(Player* pPlayer);

void processInputs(Player* pPlayer, char cInput);
void processFastTravel(Player* pPlayer);
