#include "character_creation.h"
//annoying just to remove the error message
#include "stdio.h"

void runCharCreation(Player* player) {
    int choice = 0;
    printf("Character Creation\n");
    do {
        printCharCreationScreen(player);
        scanf("%d", &choice);
        processCharInputs(choice, player);
    } while (choice != 3 && choice != 4);
    if (choice==3)
    {
    savePlayerData(player);
    runRoundTable(player);
    }

    if (choice==4)
    {
        runTitle(player);
    }
    
    
   
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
            player->stats.health = 15;
            player->stats.endurance = 11;
            player->stats.dexterity = 13;
            player->stats.strength = 14;
            player->stats.intelligence = 9;
            player->stats.faith = 9;
            break;
        case 2:
            strcpy(player->jobName, "Samurai");
            player->level = 1;
            player->stats.health = 12;
            player->stats.endurance = 13;
            player->stats.dexterity = 15;
            player->stats.strength = 12;
            player->stats.intelligence = 9;
            player->stats.faith = 8;
            break;
        case 3:
            strcpy(player->jobName, "Warrior");
            player->level = 1;
            player->stats.health = 11;
            player->stats.endurance = 11;
            player->stats.dexterity = 16;
            player->stats.strength = 10;
            player->stats.intelligence = 10;
            player->stats.faith = 8;
            break;
        case 4:
            strcpy(player->jobName, "Hero");
            player->level = 1;
            player->stats.health = 14;
            player->stats.endurance = 12;
            player->stats.dexterity = 9;
            player->stats.strength = 16;
            player->stats.intelligence = 7;
            player->stats.faith = 8;
            break;
        case 5:
            strcpy(player->jobName, "Astrologer");
            player->level = 1;
            player->stats.health = 9;
            player->stats.endurance = 9;
            player->stats.dexterity = 12;
            player->stats.strength = 8;
            player->stats.intelligence = 16;
            player->stats.faith = 7;
            break;
        case 6:
            strcpy(player->jobName, "Prophet");
            player->level = 1;
            player->stats.health = 10;
            player->stats.endurance = 8;
            player->stats.dexterity = 10;
            player->stats.strength = 11;
            player->stats.intelligence = 7;
            player->stats.faith = 16;
            break;
        default:
            printf("Invalid job class. Please try again.\n");
            break;
    }
}

void displayCurrentCharacter(Player* player) {
    printf("Current Character Details:\n");
    if (strlen(player->name) == 0) {
        printf("Name: Not Set\n");
    } else {
        printf("Name: %s\n", player->name);
    }
    if (strlen(player->jobName) == 0) {
        printf("Job Class: Not Set\n");
    } else {
        printf("Job Class: %s\n", player->jobName);
    }
    printf("Level: %d\n", player->level);
    printf("Health: %d\n", player->stats.health);
    printf("Endurance: %d\n", player->stats.endurance);
    printf("Dexterity: %d\n", player->stats.dexterity);
    printf("Strength: %d\n", player->stats.strength);
    printf("Intelligence: %d\n", player->stats.intelligence);
    printf("Faith: %d\n", player->stats.faith);
    printf("\n");
}


void savePlayerData(Player* player) {
    FILE *file = fopen("player_data.txt", "w");
    if (file) {
        fprintf(file, "Name: %s\n", player->name);
        fprintf(file, "Job Class: %s\n", player->jobName);
        fprintf(file, "Level: %d\n", player->level);
        fprintf(file, "Health: %d\n", player->stats.health);
        fprintf(file, "Endurance: %d\n", player->stats.endurance);
        fprintf(file, "Dexterity: %d\n", player->stats.dexterity);
        fprintf(file, "Strength: %d\n", player->stats.strength);
        fprintf(file, "Intelligence: %d\n", player->stats.intelligence);
        fprintf(file, "Faith: %d\n", player->stats.faith);
        fprintf(file, "Runes: %d\n", player->runes);

        // Save shards
        fprintf(file, "Shards: %d,%d,%d,%d,%d,%d\n",
                player->nShards.nStormveil,
                player->nShards.nRaya,
                player->nShards.nRedmane,
                player->nShards.nVolcano,
                player->nShards.nLeyndell,
                player->nShards.nElden);

        // Save inventory
        fprintf(file, "Inventory:\n");
        for (int i = 0; i < player->inventorySize; i++) {
            Weapon* w = &player->inventory[i];
            fprintf(file, "%s,%d,%d,%d,%d,%d,%d,%d\n",
                    w->weapon,
                    w->nHp,
                    w->nDex,
                    w->nInt,
                    w->nEnd,
                    w->nStr,
                    w->nFth,
                    w->nCost);
        }

        fclose(file);
        printf("Player data saved to player_data.txt.\n");
    } else {
        printf("Error: Could not open file for writing.\n");
    }
}

void readPlayerData(Player* player) {
    FILE *file = fopen("player_data.txt", "r");
    if (file) {
        fscanf(file, "Name: %25[^\n]\n", player->name);
        fscanf(file, "Job Class: %25[^\n]\n", player->jobName);
        fscanf(file, "Level: %d\n", &player->level);
        fscanf(file, "Health: %d\n", &player->stats.health);
        fscanf(file, "Endurance: %d\n", &player->stats.endurance);
        fscanf(file, "Dexterity: %d\n", &player->stats.dexterity);
        fscanf(file, "Strength: %d\n", &player->stats.strength);
        fscanf(file, "Intelligence: %d\n", &player->stats.intelligence);
        fscanf(file, "Faith: %d\n", &player->stats.faith);
        fscanf(file, "Runes: %d\n", &player->runes);

        // Load shards
        fscanf(file, "Shards: %d,%d,%d,%d,%d,%d\n",
               &player->nShards.nStormveil,
               &player->nShards.nRaya,
               &player->nShards.nRedmane,
               &player->nShards.nVolcano,
               &player->nShards.nLeyndell,
               &player->nShards.nElden);

        // Load inventory
        char line[256];
        fgets(line, sizeof(line), file); // Skip "Inventory:" line
        player->inventorySize = 0; // Reset inventory size

        while (fgets(line, sizeof(line), file)) {
            if (strcmp(line, "\n") == 0) break; // End of inventory section

            if (player->inventorySize >= player->inventoryCapacity) {
                // Increase capacity
                player->inventoryCapacity *= 2;
                player->inventory = realloc(player->inventory, player->inventoryCapacity * sizeof(Weapon));
                if (player->inventory == NULL) {
                    perror("Memory allocation failed");
                    fclose(file);
                    return;
                }
            }

            Weapon* w = &player->inventory[player->inventorySize];
            sscanf(line, "%[^,],%d,%d,%d,%d,%d,%d,%d",
                   w->weapon,
                   &w->nHp,
                   &w->nDex,
                   &w->nInt,
                   &w->nEnd,
                   &w->nStr,
                   &w->nFth,
                   &w->nCost);

            player->inventorySize++;
        }

        fclose(file);
        printf("Player data loaded from player_data.txt.\n");
    } else {
        printf("Error: Could not open file for reading.\n");
    }
}