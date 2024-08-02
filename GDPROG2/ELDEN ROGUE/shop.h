
#pragma once

#include "character_creation.h"
#include "title.h"
#include "structures.h"
#include "files.h"
void addWeaponToInventory(Player* player, Weapon weaponToBuy);
void buySeals(Player* plyaer);
void buyStaves(Player* player);
void buyGreatSwords(Player* player);
void buyWhips(Player* player);
void buyKatanas(Player* player);
void buySwords(Player* player);
void sellEquipment(Player* player);
void processShop(Player* player);