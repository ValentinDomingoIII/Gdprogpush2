#include "character_creation.h"

void runCharCreation(Player* pPlayer) {
    char cChoice = 0;
    int nIsConfirmed = 0; // Flag to check if character is confirmed
    int nExitCreation = 0; // Flag to check if we should exit the creation loop
    
    printf("\n\t  ▄▄█▀▀▀▄█ ▀██                                ▄                        ▄▄█▀▀▀▄█                           ▄    ██                   \n");
    printf("\t▄█▀     ▀   ██ ▄▄    ▄▄▄▄   ▄▄▄ ▄▄   ▄▄▄▄   ▄██▄    ▄▄▄▄  ▄▄▄ ▄▄     ▄█▀     ▀  ▄▄▄ ▄▄    ▄▄▄▄   ▄▄▄▄   ▄██▄  ▄▄▄    ▄▄▄   ▄▄ ▄▄▄   \n");
    printf("\t██          ██▀ ██  ▀▀ ▄██   ██▀ ▀▀ ▀▀ ▄██   ██   ▄█▄▄▄██  ██▀ ▀▀    ██          ██▀ ▀▀ ▄█▄▄▄██ ▀▀ ▄██   ██    ██  ▄█  ▀█▄  ██  ██  \n");
    printf("\t▀█▄      ▄  ██  ██  ▄█▀ ██   ██     ▄█▀ ██   ██   ██       ██        ▀█▄      ▄  ██     ██      ▄█▀ ██   ██    ██  ██   ██  ██  ██  \n");
    printf("\t ▀▀█▄▄▄▄▀  ▄██▄ ██▄ ▀█▄▄▀█▀ ▄██▄    ▀█▄▄▀█▀  ▀█▄▀  ▀█▄▄▄▀ ▄██▄        ▀▀█▄▄▄▄▀  ▄██▄     ▀█▄▄▄▀ ▀█▄▄▀█▀  ▀█▄▀ ▄██▄  ▀█▄▄█▀ ▄██▄ ██▄ \n");
    printf("\t\n");
 

     while (!nIsConfirmed && !nExitCreation) {
        printCharCreationScreen();
        scanf(" %c", &cChoice);
        processCharInputs(cChoice, pPlayer);

        if (cChoice == '3') {
            if (strlen(pPlayer->cName) == 0 || strlen(pPlayer->cJobName) == 0) {
                printf("\n\t\t\t\t\t\t\tError: cName and Job Class must be set before confirming.\n");
            } else {
                nIsConfirmed = 1;
            }
        } else if (cChoice == '0') {
            nExitCreation = 1;
        }
    }

    if (nIsConfirmed) {
        savePlayerData(pPlayer);
        runRoundTable(pPlayer);
    } else if (nExitCreation) {
        runTitle(pPlayer);
    }
}

void printCharCreationScreen() {
  //  displayCurrentCharacter(pPlayer);
  printf("\n ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════ \n");
    printf("\n\t\t\t\t\t\t\t[1] INPUT NAME\n");
    printf("\t\t\t\t\t\t\t[2] INPUT JOB CLASS\n");
    printf("\t\t\t\t\t\t\t[3] CONFIRM\n");
    printf("\t\t\t\t\t\t\t[4] VIEW CURRENT CHARACTER\n");
    printf("\t\t\t\t\t\t\t[0] BACK\n");
   
printf("\n ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════ \n");
 printf("\n\t\t\t\t\t\t\t[INPUT]:");
}

int processCharInputs(char cChoice, Player* pPlayer) {
    switch (cChoice) {
        case '1':
            runNameInput(pPlayer);
            break;
        case '2':
            runJobClassInput(pPlayer);
            break;
        case '3':
            if (strlen(pPlayer->cName) == 0 || strlen(pPlayer->cJobName) == 0) {
              
                break;
            }
            printf("Character Created!\n");
            printf("cName: %s\n", pPlayer->cName);
            printf("Job Class: %s\n", pPlayer->cJobName);
            printf("Level: %d\n", pPlayer->nLevel);
            printf("Health: %d\n", pPlayer->sStats.nHealth);
            printf("Endurance: %d\n", pPlayer->sStats.nEndurance);
            printf("Dexterity: %d\n", pPlayer->sStats.nDexterity);
            printf("Strength: %d\n", pPlayer->sStats.nStrength);
            printf("Intelligence: %d\n", pPlayer->sStats.nIntelligence);
            printf("Faith: %d\n", pPlayer->sStats.nFaith);
            pPlayer->nRunes=0;
            pPlayer->sShards.nElden=0;
            pPlayer->sShards.nLeyndell=0;
            pPlayer->sShards.nRaya=0;
            pPlayer->sShards.nRedmane=0;
            pPlayer->sShards.nStormveil=0;
            pPlayer->sShards.nVolcano=0;
            giveWeapon(pPlayer);

            clear();
            break;
        case '4':
        
            displayCurrentCharacter(pPlayer);
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

void runNameInput(Player* pPlayer) {
    char cTempName[100]; // Temporary buffer to read input

    printf("\t\t\t\t\t\t\tName (max 25 characters): ");
    scanf(" %99[^\n]", cTempName); // Read input into the temporary buffer

    // Manually copy up to 25 characters
    int i;
    for (i = 0; i < 25 && cTempName[i] != '\0'; i++) {
        pPlayer->cName[i] = cTempName[i];
    }
    pPlayer->cName[i] = '\0'; // null byte at the end

    printf("\n\t\t\t\t\t\t\t cName: %s\n", pPlayer->cName);
}

void runJobClassInput(Player* pPlayer) {
    int jobClass;
    printf("\n\t\t\t\t\t\t\t Select Job Class:\n");
    printf("\t\t\t\t\t\t [1] Vagabond\t\t[4] Hero\n");
    printf("\t\t\t\t\t\t [2] Samurai\t\t[5] Astrologer\n");
    printf("\t\t\t\t\t\t [3] Warrior\t\t[6] Prophet\n");
  
    printf("\t\t\t\t\t\t\tEnter Choice: ");
    scanf("%d", &jobClass);
    setJobClass(pPlayer, jobClass);
}

void setJobClass(Player* pPlayer, int jobClass) {
    switch (jobClass) {
        case 1:
            strcpy(pPlayer->cJobName, "Vagabond");
            pPlayer->nLevel = 1;
            pPlayer->sStats.nHealth = 15;
            pPlayer->sStats.nEndurance = 11;
            pPlayer->sStats.nDexterity = 13;
            pPlayer->sStats.nStrength = 14;
            pPlayer->sStats.nIntelligence = 9;
            pPlayer->sStats.nFaith = 9;
            break;
        case 2:
            strcpy(pPlayer->cJobName, "Samurai");
            pPlayer->nLevel = 1;
            pPlayer->sStats.nHealth = 12;
            pPlayer->sStats.nEndurance = 13;
            pPlayer->sStats.nDexterity = 15;
            pPlayer->sStats.nStrength = 12;
            pPlayer->sStats.nIntelligence = 9;
            pPlayer->sStats.nFaith = 8;
            break;
        case 3:
            strcpy(pPlayer->cJobName, "Warrior");
            pPlayer->nLevel = 1;
            pPlayer->sStats.nHealth = 11;
            pPlayer->sStats.nEndurance = 11;
            pPlayer->sStats.nDexterity = 16;
            pPlayer->sStats.nStrength = 10;
            pPlayer->sStats.nIntelligence = 10;
            pPlayer->sStats.nFaith = 8;
            break;
        case 4:
            strcpy(pPlayer->cJobName, "Hero");
            pPlayer->nLevel = 1;
            pPlayer->sStats.nHealth = 14;
            pPlayer->sStats.nEndurance = 12;
            pPlayer->sStats.nDexterity = 9;
            pPlayer->sStats.nStrength = 16;
            pPlayer->sStats.nIntelligence = 7;
            pPlayer->sStats.nFaith = 8;
            break;
        case 5:
            strcpy(pPlayer->cJobName, "Astrologer");
            pPlayer->nLevel = 1;
            pPlayer->sStats.nHealth = 9;
            pPlayer->sStats.nEndurance = 9;
            pPlayer->sStats.nDexterity = 12;
            pPlayer->sStats.nStrength = 8;
            pPlayer->sStats.nIntelligence = 16;
            pPlayer->sStats.nFaith = 7;
            break;
        case 6:
            strcpy(pPlayer->cJobName, "Prophet");
            pPlayer->nLevel = 1;
            pPlayer->sStats.nHealth = 10;
            pPlayer->sStats.nEndurance = 8;
            pPlayer->sStats.nDexterity = 10;
            pPlayer->sStats.nStrength = 11;
            pPlayer->sStats.nIntelligence = 7;
            pPlayer->sStats.nFaith = 16;
            break;
        default:
            printf("Invalid job class. Please try again.\n");
            break;
    }
}

void displayCurrentCharacter(Player* pPlayer) {
    printf("\t\t\t\t\t\t\t Current Character Details:\n");
    if (strlen(pPlayer->cName) == 0) {
        printf("\t\t\t\t\t\t\t Name: Not Set\n");
    } else {
        printf("\t\t\t\t\t\t\t Name: %s\n", pPlayer->cName);
    }
    if (strlen(pPlayer->cJobName) == 0) {
        printf("\t\t\t\t\t\t\t Job Class: Not Set\n");
    } else {
        printf("\t\t\t\t\t\t\t Job Class: %s\n", pPlayer->cJobName);
    }
    printf("\t\t\t\t\t\t\t Level: %d\t Strength: %d\n", pPlayer->nLevel, pPlayer->sStats.nStrength);
    printf("\t\t\t\t\t\t\t Health: %d\t Intelligence: %d\n", pPlayer->sStats.nHealth,pPlayer->sStats.nIntelligence);
    printf("\t\t\t\t\t\t\t Endurance: %d\t Faith: %d\n", pPlayer->sStats.nEndurance,pPlayer->sStats.nFaith);
    printf("\t\t\t\t\t\t\t Dexterity: %d\n", pPlayer->sStats.nDexterity);

    printf("\n");
}



