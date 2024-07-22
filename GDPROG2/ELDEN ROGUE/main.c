#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "time.h"

#include "title.c"
#include "character_creation.c"
#include "area.c"
#include "continue.c"
#include "RoundTable.c"

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
    runTitle(&player);
    // initializeStormveil();
    
    return 0;
}
