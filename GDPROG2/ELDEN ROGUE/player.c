 #include "player.h"






 void resetInventory(Player* player) {
    // Optionally reallocate to shrink the inventory capacity
    player->inventoryCapacity = 1; // Reset to initial capacity
    player->inventory = realloc(player->inventory, player->inventoryCapacity * sizeof(Weapon));
    player->inventorySize = 0; // Reset inventory size to 0
    //printf("Inventory has been reset.\n");
}




void giveWeapon(Player* player)
{
     // Add a weapon to the player's inventory
    Weapon starterWeapon;
    strcpy(starterWeapon.weapon, "Starter Sword");
    starterWeapon.nHp = 10;
    starterWeapon.nStr = 5;
    starterWeapon.nDex = 5;
    starterWeapon.nInt = 5;
    starterWeapon.nEnd = 5;
    starterWeapon.nFth = 5;
    
    // Assuming the inventory is dynamically allocated or has a fixed size and player->inventorySize keeps track of the number of items
    player->inventory[0] = starterWeapon;
    player->inventorySize = 1;

    // Equip the weapon
    player->equippedWeapon = &player->inventory[0];
}




 void initializePlayer()
  {
    Player player;
    strcpy(player.name,"");
    strcpy(player.jobName,"");
            player.level = 1;
            player.stats.health = 0;
            player.stats.endurance = 0;
            player.stats.dexterity = 0;
            player.stats.strength = 0;
            player.stats.intelligence = 0;
            player.stats.faith = 0;
            //test runes
            player.runes = 500000;
            player.nShards.nStormveil = 0;
            player.nShards.nRaya = 0;
            player.nShards.nRedmane = 0;
            player.nShards.nVolcano = 0;
            player.nShards.nLeyndell = 0;
            player.nShards.nElden = 0;
            player.equippedWeapon = NULL;  // Initialize equippedWeapon to NULL

             int initialCapacity = 1;  // initial capacity
             player.inventory = malloc(initialCapacity * sizeof(Weapon));
             resetInventory(&player);
              giveWeapon(&player);
             runTitle(&player);
                // Free allocated memory
    for (int i = 0; i < player.inventorySize; i++) {
        free(player.inventory[i].weapon); // Free each weapon name
    }
    free(player.inventory);
  }