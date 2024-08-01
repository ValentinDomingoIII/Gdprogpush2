#pragma once
// #define MAX_NAME 26
#include "title.h"
#include "round_table.h"
#include "area.h"
#include "files.h"
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
int processCharInputs(char cChoice, Player* player);
void runNameInput(Player* player);
void runJobClassInput(Player* player);
void displayCurrentCharacter(Player* player);
void setJobClass(Player* player, int jobClass);

