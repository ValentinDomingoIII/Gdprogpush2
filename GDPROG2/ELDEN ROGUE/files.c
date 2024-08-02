#include "files.h"

void savePlayerData(Player* player) {
    FILE *file = fopen("player_data.txt", "w");
    if (file) {
        fprintf(file, "Name: %s\n", player->cName);
        fprintf(file, "Job Class: %s\n", player->cJobName);
        fprintf(file, "Level: %d\n", player->nLevel);
        fprintf(file, "Health: %d\n", player->sStats.nHealth);
        fprintf(file, "Endurance: %d\n", player->sStats.nEndurance);
        fprintf(file, "Dexterity: %d\n", player->sStats.nDexterity);
        fprintf(file, "Strength: %d\n", player->sStats.nStrength);
        fprintf(file, "Intelligence: %d\n", player->sStats.nIntelligence);
        fprintf(file, "Faith: %d\n", player->sStats.nFaith);
        fprintf(file, "Runes: %d\n", player->nRunes);

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
        for (int i = 0; i < player->nInventorySize; i++) {
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
        fscanf(file, "Name: %25[^\n]\n", player->cName);
        fscanf(file, "Job Class: %25[^\n]\n", player->cJobName);
        fscanf(file, "Level: %d\n", &player->nLevel);
        fscanf(file, "Health: %d\n", &player->sStats.nHealth);
        fscanf(file, "Endurance: %d\n", &player->sStats.nEndurance);
        fscanf(file, "Dexterity: %d\n", &player->sStats.nDexterity);
        fscanf(file, "Strength: %d\n", &player->sStats.nStrength);
        fscanf(file, "Intelligence: %d\n", &player->sStats.nIntelligence);
        fscanf(file, "Faith: %d\n", &player->sStats.nFaith);
        fscanf(file, "Runes: %d\n", &player->nRunes);

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
        player->nInventorySize = 0; // Reset inventory size

        while (fgets(line, sizeof(line), file)) {
            if (strcmp(line, "\n") == 0) break; // End of inventory section

            if (player->nInventorySize >= player->nInventoryCapacity) {
                // Increase capacity
                player->nInventoryCapacity *= 2;
                player->inventory = realloc(player->inventory, player->nInventoryCapacity * sizeof(Weapon));
                if (player->inventory == NULL) {
                    perror("Memory allocation failed");
                    fclose(file);
                    return;
                }
            }

            Weapon* w = &player->inventory[player->nInventorySize];
            sscanf(line, "%[^,],%d,%d,%d,%d,%d,%d,%d",
                   w->weapon,
                   &w->nHp,
                   &w->nDex,
                   &w->nInt,
                   &w->nEnd,
                   &w->nStr,
                   &w->nFth,
                   &w->nCost);

            player->nInventorySize++;
        }

        fclose(file);
        printf("Player data loaded from player_data.txt.\n");
    } else {
        printf("Error: Could not open file for reading.\n");
    }
}
