#include "character_creation.h"
#include "title.h"

void runCharCreation(Player* player) {
    int choice = 0;
    printf("Character Creation\n");
    do {
        printCharCreationScreen(player);
        scanf("%d", &choice);
        processCharInputs(choice, player);
    } while (choice != 3 && choice != 4);
}

void printCharCreationScreen(Player* player) {
    displayCurrentCharacter(player);
    printf("1. INPUT NAME\n");
    printf("2. INPUT JOB CLASS\n");
    printf("3. CONFIRM\n");
    printf("4. BACK\n");
}

int processCharInputs(int choice, Player* player) {
    switch (choice) {
        case 1:
            runNameInput(player);
            break;
        case 2:
            runJobClassInput(player);
            break;
        case 3:
            printf("Character Created!\n");
            printf("Name: %s\n", player->name);
            printf("Job Class: %s\n", player->jobName);
            printf("Level: %d\n", player->level);
            printf("Health: %d\n", player->stats.health);
            printf("Endurance: %d\n", player->stats.endurance);
            printf("Dexterity: %d\n", player->stats.dexterity);
            printf("Strength: %d\n", player->stats.strength);
            printf("Intelligence: %d\n", player->stats.intelligence);
            printf("Faith: %d\n", player->stats.faith);
            break;
        case 4:
            printf("Exiting Character Creation...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    return 0;
}

void runNameInput(Player* player) {
    printf("Name: ");
    scanf(" %25[^\n]", player->name);
    printf("\nName: %s\n", player->name);
}

void runJobClassInput(Player* player) {
    int jobClass;
    printf("Select Job Class:\n");
    printf("1. Vagabond\n");
    printf("2. Samurai\n");
    printf("3. Warrior\n");
    printf("4. Hero\n");
    printf("5. Astrologer\n");
    printf("6. Prophet\n");
    printf("Enter choice: ");
    scanf("%d", &jobClass);
    setJobClass(player, jobClass);
}

void setJobClass(Player* player, int jobClass) {
    switch (jobClass) {
        case 1:
            strcpy(player->jobName, "Vagabond");
            player->level = 1;
            player->stats.health = 100;
            player->stats.endurance = 50;
            player->stats.dexterity = 30;
            player->stats.strength = 70;
            player->stats.intelligence = 20;
            player->stats.faith = 15;
            break;
        case 2:
            strcpy(player->jobName, "Samurai");
            player->level = 1;
            player->stats.health = 90;
            player->stats.endurance = 60;
            player->stats.dexterity = 70;
            player->stats.strength = 50;
            player->stats.intelligence = 25;
            player->stats.faith = 10;
            break;
        case 3:
            strcpy(player->jobName, "Warrior");
            player->level = 1;
            player->stats.health = 95;
            player->stats.endurance = 55;
            player->stats.dexterity = 60;
            player->stats.strength = 60;
            player->stats.intelligence = 20;
            player->stats.faith = 10;
            break;
        case 4:
            strcpy(player->jobName, "Hero");
            player->level = 1;
            player->stats.health = 85;
            player->stats.endurance = 65;
            player->stats.dexterity = 40;
            player->stats.strength = 80;
            player->stats.intelligence = 15;
            player->stats.faith = 20;
            break;
        case 5:
            strcpy(player->jobName, "Astrologer");
            player->level = 1;
            player->stats.health = 70;
            player->stats.endurance = 40;
            player->stats.dexterity = 30;
            player->stats.strength = 20;
            player->stats.intelligence = 90;
            player->stats.faith = 30;
            break;
        case 6:
            strcpy(player->jobName, "Prophet");
            player->level = 1;
            player->stats.health = 80;
            player->stats.endurance = 45;
            player->stats.dexterity = 35;
            player->stats.strength = 25;
            player->stats.intelligence = 40;
            player->stats.faith = 90;
            break;
        default:
            printf("Invalid job class. Please try again.\n");
            break;
    }
}

void displayCurrentCharacter(Player* player) {
    printf("Current Character Details:\n");
    printf("Name: %s\n", player->name[0] ? player->name : "Not Set");
    printf("Job Class: %s\n", player->jobName[0] ? player->jobName : "Not Set");
    printf("Level: %d\n", player->level);
    printf("Health: %d\n", player->stats.health);
    printf("Endurance: %d\n", player->stats.endurance);
    printf("Dexterity: %d\n", player->stats.dexterity);
    printf("Strength: %d\n", player->stats.strength);
    printf("Intelligence: %d\n", player->stats.intelligence);
    printf("Faith: %d\n", player->stats.faith);
    printf("\n");
}