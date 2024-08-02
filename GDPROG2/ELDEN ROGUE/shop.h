
#pragma once

#include "character_creation.h"
#include "title.h"
#include "structures.h"
#include "files.h"

void addWeaponToInventory(Player* pPlayer, Weapon weaponToBuy);
void buySeals(Player* plyaer);
void buyStaves(Player* pPlayer);
void buyGreatSwords(Player* pPlayer);
void buyWhips(Player* pPlayer);
void buyKatanas(Player* pPlayer);
void buySwords(Player* pPlayer);
void sellEquipment(Player* pPlayer);
void processShop(Player* pPlayer);