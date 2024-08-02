#include "character_creation.h"
//annoying just to remove the error message
//#include "stdio.h"

void runCharCreation(Player* player) {
    char cChoice = 0;
    int isConfirmed = 0; // Flag to check if character is confirmed
    int exitCreation = 0; // Flag to check if we should exit the creation loop
    /*




                        BEEEG SPPAAACCCEE FOOORR NOOOO RREEEAAAASSOOOONN
                                                                                                                                    
                                                                                                                                    

    */
    printf("\n\t  ▄▄█▀▀▀▄█ ▀██                                ▄                        ▄▄█▀▀▀▄█                           ▄    ██                   \n");
    printf("\t▄█▀     ▀   ██ ▄▄    ▄▄▄▄   ▄▄▄ ▄▄   ▄▄▄▄   ▄██▄    ▄▄▄▄  ▄▄▄ ▄▄     ▄█▀     ▀  ▄▄▄ ▄▄    ▄▄▄▄   ▄▄▄▄   ▄██▄  ▄▄▄    ▄▄▄   ▄▄ ▄▄▄   \n");
    printf("\t██          ██▀ ██  ▀▀ ▄██   ██▀ ▀▀ ▀▀ ▄██   ██   ▄█▄▄▄██  ██▀ ▀▀    ██          ██▀ ▀▀ ▄█▄▄▄██ ▀▀ ▄██   ██    ██  ▄█  ▀█▄  ██  ██  \n");
    printf("\t▀█▄      ▄  ██  ██  ▄█▀ ██   ██     ▄█▀ ██   ██   ██       ██        ▀█▄      ▄  ██     ██      ▄█▀ ██   ██    ██  ██   ██  ██  ██  \n");
    printf("\t ▀▀█▄▄▄▄▀  ▄██▄ ██▄ ▀█▄▄▀█▀ ▄██▄    ▀█▄▄▀█▀  ▀█▄▀  ▀█▄▄▄▀ ▄██▄        ▀▀█▄▄▄▄▀  ▄██▄     ▀█▄▄▄▀ ▀█▄▄▀█▀  ▀█▄▀ ▄██▄  ▀█▄▄█▀ ▄██▄ ██▄ \n");
    printf("\t\n");
 

     while (!isConfirmed && !exitCreation) {
        printCharCreationScreen();
        scanf(" %c", &cChoice);
        processCharInputs(cChoice, player);

        if (cChoice == '3') {
            if (strlen(player->cName) == 0 || strlen(player->cJobName) == 0) {
                printf("\n\t\t\t\t\t\t\tError: cName and Job Class must be set before confirming.\n");
            } else {
                isConfirmed = 1;
            }
        } else if (cChoice == '0') {
            exitCreation = 1;
        }
    }

    if (isConfirmed) {
        savePlayerData(player);
        runRoundTable(player);
    } else if (exitCreation) {
        runTitle(player);
    }
}

void printCharCreationScreen() {
  //  displayCurrentCharacter(player);
  printf("\n ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════ \n");
    printf("\n\t\t\t\t\t\t\t[1] INPUT cName\n");
    printf("\t\t\t\t\t\t\t[2] INPUT JOB CLASS\n");
    printf("\t\t\t\t\t\t\t[3] CONFIRM\n");
    printf("\t\t\t\t\t\t\t[4] VIEW CURRENT CHARACTER\n");
    printf("\t\t\t\t\t\t\t[0] BACK\n");
   
printf("\n ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════ \n");
 printf("\n\t\t\t\t\t\t\t[INPUT]:");
}

int processCharInputs(char cChoice, Player* player) {
    switch (cChoice) {
        case '1':
            runNameInput(player);
            break;
        case '2':
            runJobClassInput(player);
            break;
        case '3':
            if (strlen(player->cName) == 0 || strlen(player->cJobName) == 0) {
              
                break;
            }
            printf("Character Created!\n");
            printf("cName: %s\n", player->cName);
            printf("Job Class: %s\n", player->cJobName);
            printf("Level: %d\n", player->nLevel);
            printf("Health: %d\n", player->sStats.nHealth);
            printf("Endurance: %d\n", player->sStats.nEndurance);
            printf("Dexterity: %d\n", player->sStats.nDexterity);
            printf("Strength: %d\n", player->sStats.nStrength);
            printf("Intelligence: %d\n", player->sStats.nIntelligence);
            printf("Faith: %d\n", player->sStats.nFaith);
            player->nRunes=0;
            player->nShards.nElden=0;
            player->nShards.nLeyndell=0;
            player->nShards.nRaya=0;
            player->nShards.nRedmane=0;
            player->nShards.nStormveil=0;
            player->nShards.nVolcano=0;
            giveWeapon(player);

            clear();
            break;
        case '4':
        
            displayCurrentCharacter(player);
            break;
        case '0':
            printf("Exiting Character Creation...\n");
            break;
        default:
            printf("Invalid Choice. Please try again.\n");
            break;
    }
    return 0;
}

void runNameInput(Player* player) {
    char cTempName[100]; // Temporary buffer to read input

    printf("\t\t\t\t\t\t\tName (max 25 characters): ");
    scanf(" %99[^\n]", cTempName); // Read input into the temporary buffer

    // Manually copy up to 25 characters
    int i;
    for (i = 0; i < 25 && cTempName[i] != '\0'; i++) {
        player->cName[i] = cTempName[i];
    }
    player->cName[i] = '\0'; // null byte at the end

    printf("\n\t\t\t\t\t\t\t cName: %s\n", player->cName);
}

void runJobClassInput(Player* player) {
    int jobClass;
    printf("\n\t\t\t\t\t\t\t Select Job Class:\n");
    printf("\t\t\t\t\t\t [1] Vagabond\t\t[4] Hero\n");
    printf("\t\t\t\t\t\t [2] Samurai\t\t[5] Astrologer\n");
    printf("\t\t\t\t\t\t [3] Warrior\t\t[6] Prophet\n");
  
    printf("\t\t\t\t\t\t\tEnter Choice: ");
    scanf("%d", &jobClass);
    setJobClass(player, jobClass);
}

void setJobClass(Player* player, int jobClass) {
    switch (jobClass) {
        case 1:
            strcpy(player->cJobName, "Vagabond");
            player->nLevel = 1;
            player->sStats.nHealth = 15;
            player->sStats.nEndurance = 11;
            player->sStats.nDexterity = 13;
            player->sStats.nStrength = 14;
            player->sStats.nIntelligence = 9;
            player->sStats.nFaith = 9;
            break;
        case 2:
            strcpy(player->cJobName, "Samurai");
            player->nLevel = 1;
            player->sStats.nHealth = 12;
            player->sStats.nEndurance = 13;
            player->sStats.nDexterity = 15;
            player->sStats.nStrength = 12;
            player->sStats.nIntelligence = 9;
            player->sStats.nFaith = 8;
            break;
        case 3:
            strcpy(player->cJobName, "Warrior");
            player->nLevel = 1;
            player->sStats.nHealth = 11;
            player->sStats.nEndurance = 11;
            player->sStats.nDexterity = 16;
            player->sStats.nStrength = 10;
            player->sStats.nIntelligence = 10;
            player->sStats.nFaith = 8;
            break;
        case 4:
            strcpy(player->cJobName, "Hero");
            player->nLevel = 1;
            player->sStats.nHealth = 14;
            player->sStats.nEndurance = 12;
            player->sStats.nDexterity = 9;
            player->sStats.nStrength = 16;
            player->sStats.nIntelligence = 7;
            player->sStats.nFaith = 8;
            break;
        case 5:
            strcpy(player->cJobName, "Astrologer");
            player->nLevel = 1;
            player->sStats.nHealth = 9;
            player->sStats.nEndurance = 9;
            player->sStats.nDexterity = 12;
            player->sStats.nStrength = 8;
            player->sStats.nIntelligence = 16;
            player->sStats.nFaith = 7;
            break;
        case 6:
            strcpy(player->cJobName, "Prophet");
            player->nLevel = 1;
            player->sStats.nHealth = 10;
            player->sStats.nEndurance = 8;
            player->sStats.nDexterity = 10;
            player->sStats.nStrength = 11;
            player->sStats.nIntelligence = 7;
            player->sStats.nFaith = 16;
            break;
        default:
            printf("Invalid job class. Please try again.\n");
            break;
    }
}

void displayCurrentCharacter(Player* player) {
    printf("\t\t\t\t\t\t\t Current Character Details:\n");
    if (strlen(player->cName) == 0) {
        printf("\t\t\t\t\t\t\t Name: Not Set\n");
    } else {
        printf("\t\t\t\t\t\t\t Name: %s\n", player->cName);
    }
    if (strlen(player->cJobName) == 0) {
        printf("\t\t\t\t\t\t\t Job Class: Not Set\n");
    } else {
        printf("\t\t\t\t\t\t\t Job Class: %s\n", player->cJobName);
    }
    printf("\t\t\t\t\t\t\t Level: %d\t Strength: %d\n", player->nLevel, player->sStats.nStrength);
    printf("\t\t\t\t\t\t\t Health: %d\t Intelligence: %d\n", player->sStats.nHealth,player->sStats.nIntelligence);
    printf("\t\t\t\t\t\t\t Endurance: %d\t Faith: %d\n", player->sStats.nEndurance,player->sStats.nFaith);
    printf("\t\t\t\t\t\t\t Dexterity: %d\n", player->sStats.nDexterity);

    printf("\n");
}



