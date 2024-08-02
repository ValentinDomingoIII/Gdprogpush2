#include "title.h"
#include "character_creation.h"

void runTitle(Player* pPlayer) {
   // initializePlayer();
    char cInput = 'a';

    while (cInput != '0') {
        printf("\n");
        displayTitle();
        scanf(" %c", &cInput);
        processTitle(&cInput, pPlayer);
    }
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

void processTitle(char* cInput, Player* pPlayer) {
    switch (*cInput) {
        case '1':
            runCharCreation(pPlayer);
            break;
        case '2':
            readPlayerData(pPlayer);
            displayCurrentCharacter(pPlayer);
            runRoundTable(pPlayer);
            break;
        case '0':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}
