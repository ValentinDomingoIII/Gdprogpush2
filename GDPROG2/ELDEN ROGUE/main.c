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
            player.nShards.nRedmane = 0;
            player.nShards.nVolcano = 0;
            player.nShards.nLeyndell = 1;
            player.nShards.nElden = 0;
            
    runTitle(&player);
    
    
    return 0;
}
