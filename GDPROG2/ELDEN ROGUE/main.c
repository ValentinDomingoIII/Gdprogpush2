#include "title.c"
#include "character_creation.c"

int main() {
    system("chcp 65001");
    Player player = {"", "", 0, {0, 0, 0, 0, 0, 0}};
    runTitle(&player);
    return 0;
}
