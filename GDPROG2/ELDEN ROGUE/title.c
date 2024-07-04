#include "title.h"
#include "character_creation.h"

void runTitle(Player* player) {
    int nInput = 0;

    do {
        printf("\n");
        displayTitle();
        scanf("%d", &nInput);
        processTitle(&nInput, player);
    } while (nInput != 0);
}

void displayTitle() {
    printf("\t╔═════════════════════╗\n");
    printf("\t│     ELDEN ROGUE     │\n");
    printf("\t╚═════════════════════╝\n");
    printf("\t[1] START\n");
    printf("\t[2] CONTINUE\n");
    printf("\t[0] EXIT\n");
    printf("\n\t[INPUT]: ");
}

void processTitle(int* nInput, Player* player) {
    switch (*nInput) {
        case 1:
            runCharCreation(player);
            break;
        case 2:
            
            
            break;
        case 0:
            printf("Exiting...\n");
            *nInput = 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}
