
#include "round_table.h"

void runRoundTable(Player* player)
{
    char cInput;
   // printf("\nWELCOME\n");

   giveWeapon(player);
  do
  {
    player->nPotions = 8;
    displayRoundTable(player);
    scanf(" %c",&cInput);
    processInputs(player,cInput);
  } while (cInput!='0');

  initializePlayer();
     
}

void displayRoundTable(Player* player)
{
    printf("\n");
    printf("\x1b[48;5;242m╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\x1b[0m\n");
    printf("\x1b[48;5;242m║   ▀██▀▀█▄    ▄▄█▀▀██   ▀██▀  ▀█▀ ▀█▄   ▀█▀ ▀██▀▀█▄   █▀▀██▀▀█     █     ▀██▀▀█▄   ▀██▀      ▀██▀▀▀▀█     ▀██▀  ▀██▀  ▄▄█▀▀██   ▀██▀      ▀██▀▀█▄   ║\x1b[0m\n");
    printf("\x1b[48;5;242m║    ██   ██  ▄█▀    ██   ██    █   █▀█   █   ██   ██     ██       ███     ██   ██   ██        ██  ▄        ██    ██  ▄█▀    ██   ██        ██   ██  ║\x1b[0m\n");
    printf("\x1b[48;5;242m║    ██▀▀█▀   ██      ██  ██    █   █ ▀█▄ █   ██    ██    ██      █  ██    ██▀▀▀█▄   ██        ██▀▀█        ██▀▀▀▀██  ██      ██  ██        ██    ██ ║\x1b[0m\n");
    printf("\x1b[48;5;242m║    ██   █▄  ▀█▄     ██  ██    █   █   ███   ██    ██    ██     ▄▀▀▀▀█▄   ██    ██  ██        ██           ██    ██  ▀█▄     ██  ██        ██    ██ ║\x1b[0m\n");
    printf("\x1b[48;5;242m║   ▄██▄  ▀█▀  ▀▀█▄▄▄█▀    ▀█▄▄▀   ▄█▄   ▀█  ▄██▄▄▄█▀    ▄██▄   ▄█▄  ▄██▄ ▄██▄▄▄█▀  ▄██▄▄▄▄▄█ ▄██▄▄▄▄▄█    ▄██▄  ▄██▄  ▀▀█▄▄▄█▀  ▄██▄▄▄▄▄█ ▄██▄▄▄█▀  ║\x1b[0m\n");
    printf("\x1b[48;5;242m╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\x1b[0m\n");

                                                                                                                                  

// printf("\n\n\t\t\t\t\t\t\t======= ROUND TABLE =======\n");
    printf("\t\t\t\t\t\t\t Player: %s | %s\n", player->name,player->jobName);
    printf("\t\t\t\t\t\t\t Level: %d\n", player->level);
    printf("\t\t\t\t\t\t\t Runes: %d\n", player->runes);
    printf("\t\t\t\t\t\t\t Stats:\n\n");
    printf("\t\t\t\t\t\t\t Health: %d\t\t Strength: %d\n", player->stats.health,player->stats.strength);
    printf("\t\t\t\t\t\t\t Endurance: %d\t\t Intelligence: %d\n", player->stats.endurance, player->stats.intelligence);
    printf("\t\t\t\t\t\t\t Dexterity: %d\t\t Faith: %d\n", player->stats.dexterity,player->stats.faith);
 
 


 
    
     if (player->equippedWeapon == NULL)  {
        printf("\n\t\t\t\t\t\t\t No weapon equipped.\n");
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t Equipped Weapon: %s\n", player->equippedWeapon->weapon);
        printf("\t\t\t\t\t\t\t  HP: %d\t INT: %d\n", player->equippedWeapon->nHp, player->equippedWeapon->nInt);
        printf("\t\t\t\t\t\t\t  STR: %d\t END: %d\n", player->equippedWeapon->nStr, player->equippedWeapon->nEnd);
        printf("\t\t\t\t\t\t\t  DEX: %d\t FTH: %d\n", player->equippedWeapon->nDex, player->equippedWeapon->nFth);
       
        
  

    }


 printf("=============================================================================================================================================\n");
    printf("\t\t\t\t\t\t\t[1] Fast travel\n");
    printf("\t\t\t\t\t\t\t[2] Level Up\n");
    printf("\t\t\t\t\t\t\t[3] Inventory\n");
    printf("\t\t\t\t\t\t\t[4] Shop\n");
    printf("\t\t\t\t\t\t\t[5] Save\n");
    printf("\t\t\t\t\t\t\t[0] Quit Game\n");

    printf("\t\t\t\t\t\t\tINPUT:");
}


int runemath(Player* player) {
    int nRunecost = (player->level * 100) / 2;
    char trash;

    if (player->runes >= nRunecost) {
        printf("Leveled UP!\n");
        player->runes -= nRunecost;
        player->level++;
        scanf(" %c", &trash);  // This can be removed if not needed
        return 1;
    } else {
        printf("\nInsufficient Runes\n");
        printf("\nEnter any input to continue:");
        scanf(" %c", &trash);  // This can be removed if not needed
        return 0;
    }
}

void processlevelup(Player* player) {
    char cChoice, cChoice2;
    int nRune = (player->level * 100) / 2;

    do {
        nRune = (player->level * 100) / 2;
        printf("\n\t\t\t\t\t\t\tLEVEL UP\n\n");
        printf("\t\t\t\t\t\t\t[1] Level up HEALTH\t[4] Level up STRENGTH\n");
        printf("\t\t\t\t\t\t\t[2] Level up ENDURANCE\t[5] Level up INTELLIGENCE\n");
        printf("\t\t\t\t\t\t\t[3] Level up DEXTERITY\t[6] Level up FAITH\n");

        printf("\t\t\t\t\t\t\t\t\t[0] BACK\n");
        printf("\t\t\t\t\t\t\tRunes: %d", player->runes);
        printf("\n\t\t\t\t\t\t\tLevel up cost: %d\n", nRune);
        printf("\n\t\t\t\t\t\t\tINPUT: ");
        scanf(" %c", &cChoice);

        switch (cChoice) {
            case '1':
                if (player->stats.health >= 50) {
                    printf("\nHealth is maxed out at %d", player->stats.health);
                } else {
                    printf("\nLevel up Health?\n");
                    printf("[1] Yes [2] No: ");
                    scanf(" %c", &cChoice2);
                    if (cChoice2 == '1' && runemath(player)) {
                        player->stats.health++;
                        printf("\nHealth increased to %d", player->stats.health);
                    }
                }
                break;

            case '2':
                if (player->stats.endurance >= 50) {
                    printf("\nEndurance is maxed out at %d", player->stats.endurance);
                } else {
                    printf("\nLevel up Endurance?\n");
                    printf("[1] Yes [2] No: ");
                    scanf(" %c", &cChoice2);
                    if (cChoice2 == '1' && runemath(player)) {
                        player->stats.endurance++;
                        printf("\nEndurance increased to %d", player->stats.endurance);
                    }
                }
                break;

            case '3':
                if (player->stats.dexterity >= 50) {
                    printf("\nDexterity is maxed out at %d", player->stats.dexterity);
                } else {
                    printf("\nLevel up Dexterity?\n");
                    printf("[1] Yes [2] No: ");
                    scanf(" %c", &cChoice2);
                    if (cChoice2 == '1' && runemath(player)) {
                        player->stats.dexterity++;
                        printf("\nDexterity increased to %d", player->stats.dexterity);
                    }
                }
                break;

            case '4':
                if (player->stats.strength >= 50) {
                    printf("\nStrength is maxed out at %d", player->stats.strength);
                } else {
                    printf("\nLevel up Strength?\n");
                    printf("[1] Yes [2] No: ");
                    scanf(" %c", &cChoice2);
                    if (cChoice2 == '1' && runemath(player)) {
                        player->stats.strength++;
                        printf("\nStrength increased to %d", player->stats.strength);
                    }
                }
                break;

            case '5':
                if (player->stats.intelligence >= 50) {
                    printf("\nIntelligence is maxed out at %d", player->stats.intelligence);
                } else {
                    printf("\nLevel up Intelligence?\n");
                    printf("[1] Yes [2] No: ");
                    scanf(" %c", &cChoice2);
                    if (cChoice2 == '1' && runemath(player)) {
                        player->stats.intelligence++;
                        printf("\nIntelligence increased to %d", player->stats.intelligence);
                    }
                }
                break;

            case '6':
                if (player->stats.faith >= 50) {
                    printf("\nFaith is maxed out at %d", player->stats.faith);
                } else {
                    printf("\nLevel up Faith?\n");
                    printf("[1] Yes [2] No: ");
                    scanf(" %c", &cChoice2);
                    if (cChoice2 == '1' && runemath(player)) {
                        player->stats.faith++;
                        printf("\nFaith increased to %d", player->stats.faith);
                    }
                }
                break;

            case '0':
                break;

            default:
                printf("\nInvalid choice. Please select a valid option.\n");
                break;
        }
    } while (cChoice != '0');
}



void processInventory(Player* player) {
    char cChoice;
    int i;

    do {
        printf("\nINVENTORY\n");
        for (i = 0; i < player->inventorySize; i++) {
            printf("[%d] %s - HP: %d, STR: %d, DEX: %d, INT: %d, END: %d, FTH: %d\n",
                   i + 1, player->inventory[i].weapon, player->inventory[i].nHp,
                   player->inventory[i].nStr, player->inventory[i].nDex, player->inventory[i].nInt,
                   player->inventory[i].nEnd, player->inventory[i].nFth);
        }
        printf("[0] Back\n");

        printf("Choose a weapon or press '0' to go back: ");
        scanf(" %c", &cChoice);

        if (cChoice == '0') {
            return;
        }

        int index = cChoice - '1';
        if (index >= 0 && index < player->inventorySize) {
            if (player->stats.dexterity >= player->inventory[index].nDex) {
                player->equippedWeapon = &player->inventory[index];
                printf("You have equipped %s\n", player->equippedWeapon->weapon);
            } else {
                printf("You do not have enough dexterity to equip %s\n", player->inventory[index].weapon);
            }
        } else {
            printf("Invalid choice\n");
        }
    } while (1);
}

void processInputs(Player* player, char cInput)
{
    switch (cInput)
    {
    case '1':
        processFastTravel(player);
        break;
    break;
    case '2':
        processlevelup(player);
        break;
    case '3':
        processInventory(player);
    break;
    case '4':
        processShop(player);
    break;
    case '5':
        savePlayerData(player);
        break;
    default:
        break;
    }
}

void processFastTravel(Player* pPlayer)
{
    char cAreaIndex;
    char cFastTravel;
    int nTotalShards;
    int nFlag1 = 0;
    int nFlag2, nFlag3;

    nTotalShards = pPlayer->nShards.nStormveil + pPlayer->nShards.nRaya + pPlayer->nShards.nVolcano + pPlayer->nShards.nRedmane;

    do {

    do {
    
    nFlag2 = 0;
    nFlag3 = 0;
    printf("SELECT YOUR DESTINATION\n\n");
    printf("[1]: [STORMVEIL CASTLE]\n");
    printf("[2]: [RAYA LUCARIA]\n");
    printf("[3]: [REDMANE CASTLE]\n");
    printf("[4]: [VOLCANO MANOR]\n");

    if(nTotalShards < 2)
        printf("[LOCKED]: [LEYNDELL ROYAL CAPITAL]\n");
    else
        printf("[5]: [LEYNDELL ROYAL CAPITAL]\n");
    
    if(pPlayer->nShards.nLeyndell == 0)
        printf("[LOCKED]: [ELDEN THRONE]\n");
    else
        printf("[6]: [ELDEN THRONE]\n");

    printf("\n[0]: BACK\n");

    printf("\n[INPUT]: ");
    scanf(" %c", &cAreaIndex);

    if(cAreaIndex == '5' && nTotalShards < 2)
        cAreaIndex = '7';
    
    if(cAreaIndex == '6' && pPlayer->nShards.nLeyndell == 0)
        cAreaIndex = '7';

    if(cAreaIndex == '0')
        nFlag2 = 1;

    } while (cAreaIndex != '0' && cAreaIndex != '1' && cAreaIndex != '2' && cAreaIndex != '3' && cAreaIndex != '4' && cAreaIndex != '5' && cAreaIndex != '6');

    while(cFastTravel != '1' && cFastTravel != '2' && nFlag2 != 1 && nFlag3 != 1){

        printf("\nSELECT YOUR DESTINATION\n\n");
        printf("[1]: Starting Area\n");

        switch(cAreaIndex){
            case '1':
                if(pPlayer->nShards.nStormveil == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag1 = 1;
                }
                break;

            case '2':
                if(pPlayer->nShards.nRaya == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag1 = 1;
                }
                break;
            
            case '3':
                if(pPlayer->nShards.nRedmane == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag1 = 1;
                }
                break;
            
            case '4':
                if(pPlayer->nShards.nVolcano == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag1 = 1;
                }
                break;
            
            case '5':
                if(nTotalShards > 1 && pPlayer->nShards.nLeyndell == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag1 = 1;
                }
                break;
        }

        printf("\n[0]: BACK\n\n");
        printf("[INPUT]: ");
        scanf(" %c", &cFastTravel);

        if(nFlag1 == 1 && cFastTravel == '2')
            cFastTravel = 'a';

        if(cFastTravel == '0'){
            nFlag2 = 2;
            nFlag3 = 1;
        }

    };

    } while(nFlag2 != 0 && nFlag2 != 1);

    if(nFlag2 == 0 && nFlag3 == 0)
        areaSelect(cAreaIndex, cFastTravel, pPlayer);
}