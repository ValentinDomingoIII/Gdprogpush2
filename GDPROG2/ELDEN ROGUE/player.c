#include "player.h"

void resetInventory(Player* pPlayer) {
    // Optionally reallocate to shrink the inventory capacity
    pPlayer->nInventoryCapacity = 1; // Reset to initial capacity
    pPlayer->inventory = realloc(pPlayer->inventory, pPlayer->nInventoryCapacity * sizeof(Weapon));
    pPlayer->nInventorySize = 0; // Reset inventory size to 0
    //printf("Inventory has been reset.\n");
}

void giveWeapon(Player* pPlayer) {
    // Add a weapon to the pPlayer's inventory
    Weapon starterWeapon;
    strcpy(starterWeapon.weapon, "Starter Sword");
    starterWeapon.nHp = 10;
    starterWeapon.nStr = 5;
    starterWeapon.nDex = 5;
    starterWeapon.nInt = 5;
    starterWeapon.nEnd = 5;
    starterWeapon.nFth = 5;
    starterWeapon.nCost = 100; // Example cost

    // Assuming the inventory is dynamically allocated or has a fixed size and pPlayer->nInventorySize keeps track of the number of items
    pPlayer->inventory[0] = starterWeapon;
    pPlayer->nInventorySize = 1;

    // Equip the weapon
    pPlayer->equippedWeapon = &pPlayer->inventory[0];
}

void initializePlayer() {
    Player pPlayer;
    strcpy(pPlayer.cName, "");
    strcpy(pPlayer.cJobName, "");
    pPlayer.nLevel = 1;
    pPlayer.sStats.nHealth = 0;
    pPlayer.sStats.nEndurance = 0;
    pPlayer.sStats.nDexterity = 0;
    pPlayer.sStats.nStrength = 0;
    pPlayer.sStats.nIntelligence = 0;
    pPlayer.sStats.nFaith = 0;
    // Test runes
    pPlayer.nRunes = 500000;
    pPlayer.sShards.nStormveil = 0;
    pPlayer.sShards.nRaya = 0;
    pPlayer.sShards.nRedmane = 0;
    pPlayer.sShards.nVolcano = 0;
    pPlayer.sShards.nLeyndell = 0;
    pPlayer.sShards.nElden = 0;
    pPlayer.equippedWeapon = NULL;  // Initialize equippedWeapon to NULL

    int initialCapacity = 1;  // Initial capacity
    pPlayer.inventory = malloc(initialCapacity * sizeof(Weapon));
    pPlayer.nInventoryCapacity = initialCapacity; // Set the initial capacity
    resetInventory(&pPlayer);
    giveWeapon(&pPlayer);
    runTitle(&pPlayer);

    // Free allocated memory

    free(pPlayer.inventory);
}
