#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "time.h"
#include "stddef.h"

#include "player.c"
#include "title.c"
#include "character_creation.c"
#include "area.c"
#include "round_table.c"
#include "combat.c"
#include "utility.c"
#include "shop.c"
#include "files.c"
#include "level.c"
#include "inventory.c"
    
int main() {

    system("chcp 65001");
    initializePlayer();
    
    return 0;
}
