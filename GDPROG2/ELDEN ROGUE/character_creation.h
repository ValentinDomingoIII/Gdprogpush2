#pragma once
#define MAX_NAME 26

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
    Stats stats;
} Player;

void runCharCreation(Player* player);
void printCharCreationScreen();
int processCharInputs(int choice, Player* player);
void runNameInput(Player* player);
void runJobClassInput(Player* player);
void setJobClass(Player* player, int jobClass);
void savePlayerData(Player* player);
void readPlayerData(Player* player);
