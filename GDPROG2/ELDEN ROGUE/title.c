#include "title.h"
#include "character_creation.h"

void runTitle(Player* player) {
   // initializePlayer();
    int nInput = 0;

    do {
        printf("\n");
        displayTitle();
        scanf("%d", &nInput);
        processTitle(&nInput, player);
    } while (nInput != 0);
}

void displayTitle() {
printf("\t\x1b[48;5;0m                                                                                                                 \x1b[0m  \n");                                                                                                             
printf("\t\x1b[48;5;0m \x1b[38;5;220m▀███▀▀▀███▀████▀   ▀███▀▀▀██▄ ▀███▀▀▀███▀███▄   ▀███▀   ▀███▀▀▀██▄   ▄▄█▀▀██▄   ▄▄█▀▀▀█▄█▀███▀   ▀███▀███▀▀▀███ \x1b[0m \n");
printf("\t\x1b[48;5;0m \x1b[38;5;220m ██    ▀█  ██       ██    ▀██▄ ██    ▀█  ███▄    █       ██   ▀██▄▄██▀    ▀██▄██▀     ▀█ ██       █   ██    ▀█  \x1b[0m \n");
printf("\t\x1b[48;5;0m \x1b[38;5;220m ██   █    ██       ██     ▀██ ██   █    █ ███   █       ██   ▄██ ██▀      ▀███▀       ▀ ██       █   ██   █    \x1b[0m \n");
printf("\t\x1b[48;5;0m \x1b[38;5;220m ██████    ██       ██      ██ ██████    █  ▀██▄ █       ███████  ██        ███          ██       █   ██████    \x1b[0m \n");
printf("\t\x1b[48;5;0m \x1b[38;5;220m ██   █  ▄ ██     ▄ ██     ▄██ ██   █  ▄ █   ▀██▄█       ██  ██▄  ██▄      ▄███▄    ▀██████       █   ██   █  ▄ \x1b[0m \n");
printf("\t\x1b[48;5;0m \x1b[38;5;220m ██     ▄█ ██    ▄█ ██    ▄██▀ ██     ▄█ █     ███       ██   ▀██▄▀██▄    ▄██▀██▄     ██ ██▄     ▄█   ██     ▄█ \x1b[0m \n");
printf("\t\x1b[48;5;0m \x1b[38;5;220m▄███████████████████████████▀ ▄█████████████▄    ██     ▄████▄ ▄███▄ ▀▀████▀▀   ▀▀███████  ▀██████▀▀ ▄██████████ \x1b[0m \n");
printf("\t\x1b[48;5;0m                                                                                                                 \x1b[0m  \n");
 

    printf("\n\t\t\t\t\t\t\t [1] START\n");
    printf("\t\t\t\t\t\t\t [2] CONTINUE\n");
    printf("\t\t\t\t\t\t\t [0] EXIT\n");
    printf("\n\t\t\t\t\t\t\t [INPUT]: ");

                                                                                                                
                                                                                                                

  /*printf("\t╔═════════════════════╗\n");
    printf("\t│     ELDEN ROGUE     │\n");
    printf("\t╚═════════════════════╝\n");
    printf("\t[1] START\n");
    printf("\t[2] CONTINUE\n");
    printf("\t[0] EXIT\n");
    printf("\n\t[INPUT]: ");
    */
}

void processTitle(int* nInput, Player* player) {
    switch (*nInput) {
        case 1:
            runCharCreation(player);
            break;
        case 2:
            readPlayerData(player);
            displayCurrentCharacter(player);
            runRoundTable(player);
            break;
            
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
