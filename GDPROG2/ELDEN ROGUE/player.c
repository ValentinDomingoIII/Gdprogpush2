#include "player.h"

void resetInventory(Player* player) {
    // Optionally reallocate to shrink the inventory capacity
    player->nInventoryCapacity = 1; // Reset to initial capacity
    player->inventory = realloc(player->inventory, player->nInventoryCapacity * sizeof(Weapon));
    player->nInventorySize = 0; // Reset inventory size to 0
    //printf("Inventory has been reset.\n");
}

void giveWeapon(Player* player) {
    // Add a weapon to the player's inventory
    Weapon starterWeapon;
    strcpy(starterWeapon.weapon, "Starter Sword");
    starterWeapon.nHp = 10;
    starterWeapon.nStr = 5;
    starterWeapon.nDex = 5;
    starterWeapon.nInt = 5;
    starterWeapon.nEnd = 5;
    starterWeapon.nFth = 5;
    starterWeapon.nCost = 100; // Example cost

    // Assuming the inventory is dynamically allocated or has a fixed size and player->nInventorySize keeps track of the number of items
    player->inventory[0] = starterWeapon;
    player->nInventorySize = 1;

    // Equip the weapon
    player->equippedWeapon = &player->inventory[0];
}

void initializePlayer() {
    Player player;
    strcpy(player.cName, "");
    strcpy(player.cJobName, "");
    player.nLevel = 1;
    player.sStats.nHealth = 0;
    player.sStats.nEndurance = 0;
    player.sStats.nDexterity = 0;
    player.sStats.nStrength = 0;
    player.sStats.nIntelligence = 0;
    player.sStats.nFaith = 0;
    // Test runes
    player.nRunes = 500000;
    player.nShards.nStormveil = 0;
    player.nShards.nRaya = 0;
    player.nShards.nRedmane = 0;
    player.nShards.nVolcano = 0;
    player.nShards.nLeyndell = 0;
    player.nShards.nElden = 0;
    player.equippedWeapon = NULL;  // Initialize equippedWeapon to NULL

    int initialCapacity = 1;  // Initial capacity
    player.inventory = malloc(initialCapacity * sizeof(Weapon));
    player.nInventoryCapacity = initialCapacity; // Set the initial capacity
    resetInventory(&player);
    giveWeapon(&player);
    runTitle(&player);

    // Free allocated memory

    free(player.inventory);
}
