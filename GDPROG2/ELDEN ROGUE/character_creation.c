#include "character_creation.h"
//annoying just to remove the error message
//#include "stdio.h"

void runCharCreation(Player* player) {
    char cChoice = 0;
    /*




                        BEEEG SPPAAACCCEE FOOORR NOOOO RREEEAAAASSOOOONN
                                                                                                                                    
                                                                                                                                    

    */
    printf("\t  ▄▄█▀▀▀▄█ ▀██                                ▄                        ▄▄█▀▀▀▄█                           ▄    ██                   \n");
    printf("\t▄█▀     ▀   ██ ▄▄    ▄▄▄▄   ▄▄▄ ▄▄   ▄▄▄▄   ▄██▄    ▄▄▄▄  ▄▄▄ ▄▄     ▄█▀     ▀  ▄▄▄ ▄▄    ▄▄▄▄   ▄▄▄▄   ▄██▄  ▄▄▄    ▄▄▄   ▄▄ ▄▄▄   \n");
    printf("\t██          ██▀ ██  ▀▀ ▄██   ██▀ ▀▀ ▀▀ ▄██   ██   ▄█▄▄▄██  ██▀ ▀▀    ██          ██▀ ▀▀ ▄█▄▄▄██ ▀▀ ▄██   ██    ██  ▄█  ▀█▄  ██  ██  \n");
    printf("\t▀█▄      ▄  ██  ██  ▄█▀ ██   ██     ▄█▀ ██   ██   ██       ██        ▀█▄      ▄  ██     ██      ▄█▀ ██   ██    ██  ██   ██  ██  ██  \n");
    printf("\t ▀▀█▄▄▄▄▀  ▄██▄ ██▄ ▀█▄▄▀█▀ ▄██▄    ▀█▄▄▀█▀  ▀█▄▀  ▀█▄▄▄▀ ▄██▄        ▀▀█▄▄▄▄▀  ▄██▄     ▀█▄▄▄▀ ▀█▄▄▀█▀  ▀█▄▀ ▄██▄  ▀█▄▄█▀ ▄██▄ ██▄ \n");
    printf("\t\n");
 

   do {
        printCharCreationScreen();
        scanf(" %c", &cChoice);
        processCharInputs(cChoice, player);
        if (cChoice == 3 && (strlen(player->name) == 0 || strlen(player->jobName) == 0))
         {
            cChoice = -1; // Reset Choice to continue the loop
        }
    } while (cChoice != '3' && cChoice != '0');
    if (cChoice=='3')
    {
    savePlayerData(player);
    runRoundTable(player);
    }

    if (cChoice=='0')
    {
        runTitle(player);
    }
    
    
   
}

void printCharCreationScreen() {
  //  displayCurrentCharacter(player);
    printf("\n\t\t\t\t\t\t\t[1] INPUT NAME\n");
    printf("\t\t\t\t\t\t\t[2] INPUT JOB CLASS\n");
    printf("\t\t\t\t\t\t\t[3] CONFIRM\n");
    printf("\t\t\t\t\t\t\t[4] VIEW CURRENT CHARACTER\n");
    printf("\t\t\t\t\t\t\t[0] BACK\n");

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
            if (strlen(player->name) == 0 || strlen(player->jobName) == 0) {
                printf("\n\t\t\t\t\t\t\tError: Name and Job Class must be set before confirming.\n");
                break;
            }
            printf("Character Created!\n");
            printf("Name: %s\n", player->name);
            printf("Job Class: %s\n", player->jobName);
            printf("Level: %d\n", player->level);
            printf("Health: %d\n", player->stats.health);
            printf("Endurance: %d\n", player->stats.endurance);
            printf("Dexterity: %d\n", player->stats.dexterity);
            printf("Strength: %d\n", player->stats.strength);
            printf("Intelligence: %d\n", player->stats.intelligence);
            printf("Faith: %d\n", player->stats.faith);

            
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
        player->name[i] = cTempName[i];
    }
    player->name[i] = '\0'; // null byte at the end

    printf("\n\t\t\t\t\t\t\t Name: %s\n", player->name);
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
            strcpy(player->jobName, "Vagabond");
            player->level = 1;
            player->stats.health = 15;
            player->stats.endurance = 11;
            player->stats.dexterity = 13;
            player->stats.strength = 14;
            player->stats.intelligence = 9;
            player->stats.faith = 9;
            break;
        case 2:
            strcpy(player->jobName, "Samurai");
            player->level = 1;
            player->stats.health = 12;
            player->stats.endurance = 13;
            player->stats.dexterity = 15;
            player->stats.strength = 12;
            player->stats.intelligence = 9;
            player->stats.faith = 8;
            break;
        case 3:
            strcpy(player->jobName, "Warrior");
            player->level = 1;
            player->stats.health = 11;
            player->stats.endurance = 11;
            player->stats.dexterity = 16;
            player->stats.strength = 10;
            player->stats.intelligence = 10;
            player->stats.faith = 8;
            break;
        case 4:
            strcpy(player->jobName, "Hero");
            player->level = 1;
            player->stats.health = 14;
            player->stats.endurance = 12;
            player->stats.dexterity = 9;
            player->stats.strength = 16;
            player->stats.intelligence = 7;
            player->stats.faith = 8;
            break;
        case 5:
            strcpy(player->jobName, "Astrologer");
            player->level = 1;
            player->stats.health = 9;
            player->stats.endurance = 9;
            player->stats.dexterity = 12;
            player->stats.strength = 8;
            player->stats.intelligence = 16;
            player->stats.faith = 7;
            break;
        case 6:
            strcpy(player->jobName, "Prophet");
            player->level = 1;
            player->stats.health = 10;
            player->stats.endurance = 8;
            player->stats.dexterity = 10;
            player->stats.strength = 11;
            player->stats.intelligence = 7;
            player->stats.faith = 16;
            break;
        default:
            printf("Invalid job class. Please try again.\n");
            break;
    }
}

void displayCurrentCharacter(Player* player) {
    printf("\t\t\t\t\t\t\t Current Character Details:\n");
    if (strlen(player->name) == 0) {
        printf("\t\t\t\t\t\t\t Name: Not Set\n");
    } else {
        printf("\t\t\t\t\t\t\t Name: %s\n", player->name);
    }
    if (strlen(player->jobName) == 0) {
        printf("\t\t\t\t\t\t\t Job Class: Not Set\n");
    } else {
        printf("\t\t\t\t\t\t\t Job Class: %s\n", player->jobName);
    }
    printf("\t\t\t\t\t\t\t Level: %d\t Strength: %d\n", player->level, player->stats.strength);
    printf("\t\t\t\t\t\t\t Health: %d\t Intelligence: %d\n", player->stats.health,player->stats.intelligence);
    printf("\t\t\t\t\t\t\t Endurance: %d\t Faith: %d\n", player->stats.endurance,player->stats.faith);
    printf("\t\t\t\t\t\t\t Dexterity: %d\n", player->stats.dexterity);

    printf("\n");
}



