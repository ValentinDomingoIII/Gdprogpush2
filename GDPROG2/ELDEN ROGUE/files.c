#include "files.h"

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

        // Save equipped weapon
        if (player->equippedWeapon) {
            fprintf(file, "Equipped Weapon: %s,%d,%d,%d,%d,%d,%d,%d\n",
                    player->equippedWeapon->weapon,
                    player->equippedWeapon->nHp,
                    player->equippedWeapon->nDex,
                    player->equippedWeapon->nInt,
                    player->equippedWeapon->nEnd,
                    player->equippedWeapon->nStr,
                    player->equippedWeapon->nFth,
                    player->equippedWeapon->nCost);
        } else {
            fprintf(file, "Equipped Weapon: None\n");
        }

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

        // Load equipped weapon
        char line[256];
        fgets(line, sizeof(line), file);
        if (strncmp(line, "Equipped Weapon: None", 21) != 0) {
            player->equippedWeapon = malloc(sizeof(Weapon));
            sscanf(line, "Equipped Weapon: %[^,],%d,%d,%d,%d,%d,%d,%d\n",
                   player->equippedWeapon->weapon,
                   &player->equippedWeapon->nHp,
                   &player->equippedWeapon->nDex,
                   &player->equippedWeapon->nInt,
                   &player->equippedWeapon->nEnd,
                   &player->equippedWeapon->nStr,
                   &player->equippedWeapon->nFth,
                   &player->equippedWeapon->nCost);
        } else {
            player->equippedWeapon = NULL;
        }

        // Load inventory
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
