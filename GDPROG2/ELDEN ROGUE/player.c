 #include "player.h"

 void resetInventory(Player* player) {
    // Optionally reallocate to shrink the inventory capacity
    player->inventoryCapacity = 1; // Reset to initial capacity
    player->inventory = realloc(player->inventory, player->inventoryCapacity * sizeof(Weapon));
    player->inventorySize = 0; // Reset inventory size to 0
    //printf("Inventory has been reset.\n");
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
            player.runes = 8000;
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

             runTitle(&player);
             free(player.inventory);
  }