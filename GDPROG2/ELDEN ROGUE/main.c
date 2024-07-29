#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "time.h"

#include "title.c"
#include "character_creation.c"
#include "area.c"
#include "continue.c"
#include "RoundTable.c"
#include "combat.c"
#include "color.c"


void resetInventory(Player* player) {
    // Optionally reallocate to shrink the inventory capacity
    player->inventoryCapacity = 1; // Reset to initial capacity
    player->inventory = realloc(player->inventory, player->inventoryCapacity * sizeof(Weapon));
    player->inventorySize = 0; // Reset inventory size to 0
    printf("Inventory has been reset.\n");
}

//commenty
int main() {

    system("chcp 65001");
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
            player.runes=420;
            player.nShards.nStormveil = 1;
            player.nShards.nRaya = 1;
            player.nShards.nRedmane = 1;
            player.nShards.nVolcano = 1;
            player.nShards.nLeyndell = 1;
            player.nShards.nElden = 0;

             int initialCapacity = 1;  // initial capacity
             player.inventory = malloc(initialCapacity * sizeof(Weapon));
             resetInventory(&player);
    runTitle(&player);
      free(player.inventory);
    
    return 0;
}
