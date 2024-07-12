#include "stdio.h"
#include "string.h"
#include "title.c"
#include "character_creation.c"
#include "area.c"
#include "continue.c"
#include "RoundTable.c"
#include "windows.h"
int main() {

    system("chcp 65001");
    Player player = {"", "", 0, {0, 0, 0, 0, 0, 0}};
    runTitle(&player);
    // runStormveil();
    
    return 0;
}
