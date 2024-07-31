
#include "round_table.h"

void runRoundTable(Player* player)
{
    char cInput;
    printf("\nWELCOME\n");
  do
  {
    player->nPotions = 8;
    displayRoundTable(player);
    scanf(" %c",&cInput);
    processInputs(player,cInput);
  } while (cInput!='0');
     
}

void displayRoundTable(Player* player)
{
 printf("\n======= ROUND TABLE =======\n");
    printf("Player: %s\n", player->name);
    printf("Job: %s\n", player->jobName);
    printf("Level: %d\n", player->level);
    printf("Runes: %d\n", player->runes);
    printf("Stats:\n\n");
    printf("Health: %d\n", player->stats.health);
    printf("Endurance: %d\n", player->stats.endurance);
    printf("Dexterity: %d\n", player->stats.dexterity);
    printf("Strength: %d\n", player->stats.strength);
    printf("Intelligence: %d\n", player->stats.intelligence);
    printf("Faith: %d\n", player->stats.faith);


 
    
     if (player->equippedWeapon == NULL)  {
        printf("\nNo weapon equipped.\n");
    }
    else
    {
        printf("\nEquipped Weapon: %s\n", player->equippedWeapon->weapon);
        printf("  HP: %d\n", player->equippedWeapon->nHp);
        printf("  STR: %d\n", player->equippedWeapon->nStr);
        printf("  DEX: %d\n", player->equippedWeapon->nDex);
        printf("  INT: %d\n", player->equippedWeapon->nInt);
        printf("  END: %d\n", player->equippedWeapon->nEnd);
        printf("  FTH: %d\n", player->equippedWeapon->nFth);
    }


 printf("===========================\n");
    printf("[1] Fast travel\n");
    printf("[2] Level Up\n");
    printf("[3] Inventory\n");
    printf("[4] Shop\n");
    printf("[5] Save\n");
    printf("[0] Quit Game\n");

    printf("INPUT:");
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
        scanf(" %c", &trash);  // This can be removed if not needed
        return 0;
    }
}

void processlevelup(Player* player) {
    char cChoice, cChoice2;
    int nRune = (player->level * 100) / 2;

    do {
        nRune = (player->level * 100) / 2;
        printf("\nLEVEL UP\n\n");
        printf("[1] Level up DEXTERITY\n");
        printf("[2] Level up STRENGTH\n");
        printf("[3] Level up INTELLIGENCE\n");
        printf("[4] Level up FAITH\n");
        printf("[0] BACK\n");

        printf("\nLevel up cost: %d\n", nRune);
        printf("\nINPUT: ");
        scanf(" %c", &cChoice);

        switch (cChoice) {
            case '1':
                printf("\nLevel up Dexterity?\n");
                printf("[1] Yes [2] No: ");
                scanf(" %c", &cChoice2);
                if (cChoice2 == '1' && runemath(player)) {
                    player->stats.dexterity ++;  
                    printf("\nDexterity increased to %d", player->stats.dexterity);
                }
                break;

            case '2':
                printf("\nLevel up Strength?\n");
                printf("[1] Yes [2] No: ");
                scanf(" %c", &cChoice2);
                if (cChoice2 == '1' && runemath(player)) {
                    player->stats.strength ++;  
                    printf("\nStrength increased to %d", player->stats.strength);
                }
                break;

            case '3':
                printf("\nLevel up Intelligence?\n");
                printf("[1] Yes [2] No: ");
                scanf(" %c", &cChoice2);
                if (cChoice2 == '1' && runemath(player)) {
                    player->stats.intelligence ++;  
                    printf("\nIntelligence increased to %d", player->stats.intelligence);
                }
                break;

            case '4':
                printf("\nLevel up Faith?\n");
                printf("[1] Yes [2] No: ");
                scanf(" %c", &cChoice2);
                if (cChoice2 == '1' && runemath(player)) {
                    player->stats.faith ++;  
                    printf("\nFaith increased to %d", player->stats.faith);
                }
                break;

            default:
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
    int nFlag = 0;

    nTotalShards = pPlayer->nShards.nStormveil + pPlayer->nShards.nRaya + pPlayer->nShards.nVolcano + pPlayer->nShards.nRedmane;

    do {

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

    printf("\n[INPUT]: ");
    scanf(" %c", &cAreaIndex);

    if(cAreaIndex == '5' && nTotalShards < 2)
            cAreaIndex = '0';
    
    if(cAreaIndex == '6' && pPlayer->nShards.nLeyndell == 0)
        cAreaIndex = '0';

    } while (cAreaIndex != '1' && cAreaIndex != '2' && cAreaIndex != '3' && cAreaIndex != '4' && cAreaIndex != '5' && cAreaIndex != '6');

    do {

        printf("\nSELECT YOUR DESTINATION\n\n");
        printf("[1]: Starting Area\n");

        switch(cAreaIndex){
            case '1':
                if(pPlayer->nShards.nStormveil == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;

            case '2':
                if(pPlayer->nShards.nRaya == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;
            
            case '3':
                if(pPlayer->nShards.nRedmane == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;
            
            case '4':
                if(pPlayer->nShards.nVolcano == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;
            
            case '5':
                if(nTotalShards > 1 && pPlayer->nShards.nLeyndell == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;
        }

        printf("[INPUT]: ");
        scanf(" %c", &cFastTravel);

        if(nFlag == 1 && cFastTravel == '2')
            cFastTravel = '0';

    } while(cFastTravel != '1' && cFastTravel != '2');

    areaSelect(cAreaIndex, cFastTravel, pPlayer);
}