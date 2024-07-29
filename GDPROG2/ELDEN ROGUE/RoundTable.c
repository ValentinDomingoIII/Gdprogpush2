#include "character_creation.h"
#include "RoundTable.h"
#include "stdio.h"
#include "area.h"
#include "structures.h"

void runRoundTable(Player* player)
{
    char cInput;
    printf("\nWELCOME\n");
  do
  {
    displayRoundTable(player);
    scanf(" %c",&cInput);
    processInputs(player,cInput);
  } while (cInput!='0');
     
}

void displayRoundTable(Player* player)
{
    printf("Name: %s\n", player->name);
    printf("Job Class: %s\n", player->jobName);
    printf("Level: %d\n", player->level);

    printf("[1] Fast travel\n");
    printf("[2] Level Up\n");
    printf("[3] Inventory\n");
    printf("[4] Shop\n");
    printf("[5] Save\n");
    printf("[0] Quit Game\n");

    printf("INPUT:");
}


int runemath(Player* player)
{
    int nRunecost;
    char trash;
    nRunecost=(player->level*100)/2;
    if(player->runes>=nRunecost)
    {
        printf("Leveled UP!");
        player->runes=player->runes - nRunecost;
        player->level++;
        scanf(" %c",&trash);
    }
    else
    {
        printf("\nInsufficient Runes\n");
        scanf(" %c",&trash);
    }

    
}

void processlevelup(Player* player)
{
    char cChoice,cChoice2;
    int nRune=(player->level*100)/2;
    do
    {
        nRune=(player->level*100)/2;
    printf("\nLEVEL UP\n\n");
    printf("-> Level up DEXTERITY \n");
    printf("-> Level up STRENGTH \n");
    printf("-> Level up INTELLIGENCE \n");
    printf("-> Level up FAITH \n");

    
    printf("-> BACK \n");


printf("\nLevel up cost:%d\n",nRune);
printf("\nINPUT:");
    scanf(" %c",&cChoice);


    switch (cChoice)
    {
    case '1':
        printf("\nLevel up Dexerity?");
        printf("[1]Yes [2]No:");
        scanf(" %c",&cChoice2);
        if (cChoice2=='1')
        {
        
        runemath(player);
        
        printf("\n\nLevel:%d",player->level);
        printf("\n\nRUNES:%d",player->runes);
        }
        

        break;


    case '2':
        printf("\nLevel up Strength?");
        printf("[1]Yes [2]No:");
        scanf(" %c",&cChoice2);
         if (cChoice2=='1'){
        runemath(player);
        
        printf("\n\nLevel:%d",player->level);
        printf("\n\nRUNES:%d",player->runes);
         }
           break;
    
    case '3':
        printf("\nLevel up Intelligence?");
        printf("[1]Yes [2]No:");
        scanf(" %c",&cChoice2);
         if (cChoice2=='1')
         {
        runemath(player);
        
        printf("\n\nLevel:%d",player->level);
        printf("\n\nRUNES:%d",player->runes);
         }
           break;

    case '4':
        printf("\nLevel up Faith?");
        printf("[1]Yes [2]No:");
        scanf(" %c",&cChoice2);
         if (cChoice2=='1'){
        runemath(player);
        
        printf("\n\nLevel:%d",player->level);
        printf("\n\nRUNES:%d",player->runes);
         }
    
    default:
        break;
    }
    } while (cChoice!='5');
    


}


void BuySwords(Player* player)
{
    int choice;
    int cost;
    Weapon weaponToBuy;

    // Display available swords
    printf("\nAvailable Swords:\n");
    printf("1. Sword of Strength - HP: 10, STR: 5, Cost: 100\n");
    printf("2. Sword of Dexterity - HP: 8, DEX: 6, Cost: 80\n");

    printf("Enter the number of the sword you want to buy: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            weaponToBuy.nHp = 10;
            weaponToBuy.nStr = 5;
            weaponToBuy.nDex = 0;
            weaponToBuy.nInt = 0;
            weaponToBuy.nEnd = 0;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 100;
            strcpy(weaponToBuy.weapon, "Sword of Strength");
            cost = 100;
            break;
        case 2:
            weaponToBuy.nHp = 8;
            weaponToBuy.nStr = 0;
            weaponToBuy.nDex = 6;
            weaponToBuy.nInt = 0;
            weaponToBuy.nEnd = 0;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 80;
            strcpy(weaponToBuy.weapon, "Sword of Dexterity");
            cost = 80;
            break;
        default:
            printf("Invalid choice\n");
            return;
    }

    if (player->runes < cost) {
        printf("Not enough runes to buy this weapon.\n");
        return;
    }

    player->runes -= cost;



    player->inventory[player->inventorySize++] = weaponToBuy;
    printf("You have bought a %s\n", weaponToBuy.weapon);
}


void processShop(Player* player)
{
    char cChoice;
    printf("\n\tSHOP\n");

    printf("Category:\n");
    printf("[1]Swords\n");
    printf("[2]Katanas\n");
    printf("[3]Whips\n");
    printf("[4]GreatSwords\n");
    printf("[5]Staves\n");
    printf("[6]Seals\n");

    printf("INPUT:");
    scanf(" %c",&cChoice);

    switch (cChoice)
    {
    case '1':
        BuySwords(player);
        break;
    case '2':
    //    BuyKatanas(player);
    case '3':
     //   BuyWhips(player);
    case '4':
      //  BuyGreatSwords(player);
    case '5':
        //BuyStaves(player);
    case '6':
        //BuySeals(player);

    default:
        break;
    }

}

void processInventory(Player* player)

{
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
        printf("[B] Back\n");

        printf("Choose a weapon or press 'B' to go back: ");
        scanf(" %c", &cChoice);

        if (cChoice == 'B' || cChoice == 'b') {
            return;
        }

        int index = cChoice - '1';
        if (index >= 0 && index < player->inventorySize) {
            printf("You have selected %s\n", player->inventory[index].weapon);
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