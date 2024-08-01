#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "time.h"
#include "stddef.h"

#include "player.c"
#include "title.c"
#include "character_creation.c"
#include "area.c"
#include "continue.c"
#include "round_table.c"
#include "combat.c"
#include "color.c"
#include "shop.c"
#include "files.c"

int main() {

    system("chcp 65001");
    initializePlayer();
    
    return 0;
}
