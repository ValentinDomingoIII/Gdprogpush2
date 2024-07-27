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
} Inv;

typedef struct {
    int health;
    int endurance;
    int dexterity;
    int strength;
    int intelligence;
    int faith;
} Stats;

typedef struct {
    char name[MAX_NAME];
    char jobName[MAX_NAME];
    int level; 
    int runes;
    Shards nShards;
    Stats stats;
    Inv weapon;
} Player;



