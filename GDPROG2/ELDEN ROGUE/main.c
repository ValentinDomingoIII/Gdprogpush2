#include "title.c"
#include "character_creation.c"
#include "area.c"

int main() {

    system("chcp 65001");
    Player player = {"", "", 0, {0, 0, 0, 0, 0, 0}};
    runTitle(&player);
    // runStormveil();
    
    return 0;
}
