#pragma once

#include "definitions.h"

typedef char AreaName[31]; // experimental

struct array {
    int nRowSize, nColumnSize;
    int nRowOffset;
};

typedef struct array Array;

struct area {
    int aBigArray[100][21];
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
    int nFloorCount;
    int nAreaIndex;
    int nFlag;
    char strEnemy1[MAX_NAME];
    char strEnemy2[MAX_NAME];
    char strEnemy3[MAX_NAME];
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
    int health;
    int endurance;
    int dexterity;
    int strength;
    int intelligence;
    int faith;
} Stats;

typedef struct{
   // weapon weapon[];
    char cPotion;
}Inv;


typedef struct {
    char name[MAX_NAME];
    char jobName[MAX_NAME];
    int level; 
    int runes;
    Weapon *inventory;  // Dynamic array of weapons
    int inventorySize;  // Current number of weapons
    int inventoryCapacity;  // Capacity of the inventory
    Shards nShards;
    Stats stats;
    
} Player;

struct enemy {
    char strEnemyName[MAX_NAME];
    int nHealth;
    int nAttackUpper;
    int nAttackLower;
    float fPhysDef;
    float fSorcDef;
    float fIncantDef;
    int nDamage;
};

typedef struct enemy Enemy;



