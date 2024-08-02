#include "files.h"

void savePlayerData(Player* pPlayer) {
    FILE *file = fopen("player_data.txt", "w");
    if (file) {
        fprintf(file, "Name: %s\n", pPlayer->cName);
        fprintf(file, "Job Class: %s\n", pPlayer->cJobName);
        fprintf(file, "Level: %d\n", pPlayer->nLevel);
        fprintf(file, "Health: %d\n", pPlayer->sStats.nHealth);
        fprintf(file, "Endurance: %d\n", pPlayer->sStats.nEndurance);
        fprintf(file, "Dexterity: %d\n", pPlayer->sStats.nDexterity);
        fprintf(file, "Strength: %d\n", pPlayer->sStats.nStrength);
        fprintf(file, "Intelligence: %d\n", pPlayer->sStats.nIntelligence);
        fprintf(file, "Faith: %d\n", pPlayer->sStats.nFaith);
        fprintf(file, "Runes: %d\n", pPlayer->nRunes);

        // Save shards
        fprintf(file, "Shards: %d,%d,%d,%d,%d,%d\n",
                pPlayer->sShards.nStormveil,
                pPlayer->sShards.nRaya,
                pPlayer->sShards.nRedmane,
                pPlayer->sShards.nVolcano,
                pPlayer->sShards.nLeyndell,
                pPlayer->sShards.nElden);

        // Save equipped weapon
        if (pPlayer->equippedWeapon) {
            fprintf(file, "Equipped Weapon: %s,%d,%d,%d,%d,%d,%d,%d\n",
                    pPlayer->equippedWeapon->weapon,
                    pPlayer->equippedWeapon->nHp,
                    pPlayer->equippedWeapon->nDex,
                    pPlayer->equippedWeapon->nInt,
                    pPlayer->equippedWeapon->nEnd,
                    pPlayer->equippedWeapon->nStr,
                    pPlayer->equippedWeapon->nFth,
                    pPlayer->equippedWeapon->nCost);
        } else {
            fprintf(file, "Equipped Weapon: None\n");
        }

        // Save inventory
        fprintf(file, "Inventory:\n");
        for (int i = 0; i < pPlayer->nInventorySize; i++) {
            Weapon* w = &pPlayer->inventory[i];
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

void readPlayerData(Player* pPlayer) {
    FILE *file = fopen("player_data.txt", "r");
    if (file) {
        fscanf(file, "Name: %25[^\n]\n", pPlayer->cName);
        fscanf(file, "Job Class: %25[^\n]\n", pPlayer->cJobName);
        fscanf(file, "Level: %d\n", &pPlayer->nLevel);
        fscanf(file, "Health: %d\n", &pPlayer->sStats.nHealth);
        fscanf(file, "Endurance: %d\n", &pPlayer->sStats.nEndurance);
        fscanf(file, "Dexterity: %d\n", &pPlayer->sStats.nDexterity);
        fscanf(file, "Strength: %d\n", &pPlayer->sStats.nStrength);
        fscanf(file, "Intelligence: %d\n", &pPlayer->sStats.nIntelligence);
        fscanf(file, "Faith: %d\n", &pPlayer->sStats.nFaith);
        fscanf(file, "Runes: %d\n", &pPlayer->nRunes);

        // Load shards
        fscanf(file, "Shards: %d,%d,%d,%d,%d,%d\n",
               &pPlayer->sShards.nStormveil,
               &pPlayer->sShards.nRaya,
               &pPlayer->sShards.nRedmane,
               &pPlayer->sShards.nVolcano,
               &pPlayer->sShards.nLeyndell,
               &pPlayer->sShards.nElden);

        // Load equipped weapon
        char line[256];
        fgets(line, sizeof(line), file);
        if (strncmp(line, "Equipped Weapon: None", 21) != 0) {
            pPlayer->equippedWeapon = malloc(sizeof(Weapon));
            sscanf(line, "Equipped Weapon: %[^,],%d,%d,%d,%d,%d,%d,%d\n",
                   pPlayer->equippedWeapon->weapon,
                   &pPlayer->equippedWeapon->nHp,
                   &pPlayer->equippedWeapon->nDex,
                   &pPlayer->equippedWeapon->nInt,
                   &pPlayer->equippedWeapon->nEnd,
                   &pPlayer->equippedWeapon->nStr,
                   &pPlayer->equippedWeapon->nFth,
                   &pPlayer->equippedWeapon->nCost);
        } else {
            pPlayer->equippedWeapon = NULL;
        }

        // Load inventory
        fgets(line, sizeof(line), file); // Skip "Inventory:" line
        pPlayer->nInventorySize = 0; // Reset inventory size

        while (fgets(line, sizeof(line), file)) {
            if (strcmp(line, "\n") == 0) break; // End of inventory section

            if (pPlayer->nInventorySize >= pPlayer->nInventoryCapacity) {
                // Increase capacity
                pPlayer->nInventoryCapacity *= 2;
                pPlayer->inventory = realloc(pPlayer->inventory, pPlayer->nInventoryCapacity * sizeof(Weapon));
                if (pPlayer->inventory == NULL) {
                    perror("Memory allocation failed");
                    fclose(file);
                    return;
                }
            }

            Weapon* w = &pPlayer->inventory[pPlayer->nInventorySize];
            sscanf(line, "%[^,],%d,%d,%d,%d,%d,%d,%d",
                   w->weapon,
                   &w->nHp,
                   &w->nDex,
                   &w->nInt,
                   &w->nEnd,
                   &w->nStr,
                   &w->nFth,
                   &w->nCost);

            pPlayer->nInventorySize++;
        }

        fclose(file);
        printf("Player data loaded from player_data.txt.\n");
    } else {
        printf("Error: Could not open file for reading.\n");
    }
}
