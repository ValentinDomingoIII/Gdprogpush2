#pragma once
#define MAX_NAME 26
#include "title.h"
#include "RoundTable.h"
#include "area.h"
// typedef struct {
//     char weapon[MAX_NAME];
// } Inv;

// typedef struct {
//     int health;
//     int endurance;
//     int dexterity;
//     int strength;
//     int intelligence;
//     int faith;
// } Stats;

// typedef struct {
//     char name[MAX_NAME];
//     char jobName[MAX_NAME];
//     int level; 
//     int runes;
//     int shards;
//     Stats stats;
//     Inv weapon;
// } Player;


void runCharCreation(Player* player);
void printCharCreationScreen();
int processCharInputs(int choice, Player* player);
void runNameInput(Player* player);
void runJobClassInput(Player* player);
void displayCurrentCharacter(Player* player);
void setJobClass(Player* player, int jobClass);
void savePlayerData(Player* player);
void readPlayerData(Player* player);
