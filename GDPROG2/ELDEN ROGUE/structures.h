#pragma once

#include "definitions.h"

struct array {
    int nRowSize, nColumnSize;
    int nRowOffset;
};

typedef struct array Array;

struct area {
    int aBigArray[100][21];
    int nFloorCount;
    int nFloorChoice;
    int nAreaIndex;
    int nFlag;
    int nFlag2;
    int nValue;
    char strAreaName[MAX_NAME];
    char strEnemy1[MAX_NAME];
    char strEnemy2[MAX_NAME];
    char strEnemy3[MAX_NAME];
    Array a1;
    Array a2;
    Array a3;
    Array a4;
    Array a5;
    Array a6;
    Array a7;
    Array a8;
    Array a9;
    Array a10;
    Array a11;
    Array a12;
    Array a13;
    Array a14;
};

typedef struct area Area;

struct shards {
    int nStormveil;
    int nRaya;
    int nRedmane;
    int nVolcano;
    int nLeyndell;
    int nElden;
};

typedef struct shards Shards;

typedef struct {
    char weapon[MAX_NAME];
    int nHp;
    int nDex;
    int nInt;
    int nEnd;
    int nStr;
    int nFth;
    int nCost;

} Weapon;

typedef struct {
    int nHealth;
    int nEndurance;
    int nDexterity;
    int nStrength;
    int nIntelligence;
    int nFaith;
} Stats;

typedef struct{
   // weapon weapon[];
    char cPotion;
}Inv;

struct location {
    int nPreviousFloor;
};

typedef struct location Location;

struct player {
    char cName[MAX_NAME];
    char cJobName[MAX_NAME];
    int nLevel; 
    int nRunes;
    int nPotions;
    Weapon *inventory;  // Dynamic array of weapons
    int nInventorySize;  // Current number of weapons
    int nInventoryCapacity;  // Capacity of the inventory
    Weapon *equippedWeapon; // Pointer to the currently equipped weapon
    Shards nShards;
    Stats sStats;
    Location sLocation;
};

typedef struct player Player;

struct enemy {
    char strEnemyName[MAX_NAME];
    int nHealth;
    int nMaxHealth;
    int nAttackUpper;
    int nAttackLower;
    float fPhysDef;
    float fSorcDef;
    float fIncantDef;
    int nDamage;
};

typedef struct enemy Enemy;

