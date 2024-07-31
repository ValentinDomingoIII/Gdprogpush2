#include "character_creation.h"
#include "round_table.h"
#include "stdio.h"
#include "area.h"
#include "structures.h"

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


    if (player->equippedWeapon != NULL) {
        printf("\nEquipped Weapon: %s\n", player->equippedWeapon->weapon);
        printf("  HP: %d\n", player->equippedWeapon->nHp);
        printf("  STR: %d\n", player->equippedWeapon->nStr);
        printf("  DEX: %d\n", player->equippedWeapon->nDex);
        printf("  INT: %d\n", player->equippedWeapon->nInt);
        printf("  END: %d\n", player->equippedWeapon->nEnd);
        printf("  FTH: %d\n", player->equippedWeapon->nFth);
    } 
    else {
        printf("\nNo weapon equipped.\n");
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

    
    printf("[0] BACK \n");


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
    char cChoice;
    int cost;
    Weapon weaponToBuy;

    // Display available swords
    printf("\nAvailable Swords:\n");
    printf("1. Short Sword - HP: 0, STR: 15, DEX: 13, INT: 15 END: 15, FTH: 15 Cost: 100\n");
    printf("2. Roger's Rapier - HP: 10, STR: 35, DEX: 18, INT: 35, END: 25, FTH: 35 Cost: 2000\n");
    printf("3. Coded Sword - HP: 20, STR: 40, DEX: 21, INT: 40, END: 35, FTH: 40  Cost: 4000\n");
    printf("4. Sword of Night And Flame - HP: 30, STR: 55 DEX: 25, INT: 55, END: 45, FTH: 55 Cost: 8000\n");

    printf("Enter the number of the sword you want to buy: ");
    scanf(" %c", &cChoice);

    switch (cChoice) {
        case '1':
            weaponToBuy.nHp = 0;
            weaponToBuy.nStr = 15;
            weaponToBuy.nDex = 13;
            weaponToBuy.nInt = 15;
            weaponToBuy.nEnd = 15;
            weaponToBuy.nFth = 15;
            weaponToBuy.nCost = 100;
            strcpy(weaponToBuy.weapon, "Short Sword");
            cost = 100;
            break;
        case '2':
            weaponToBuy.nHp = 10;
            weaponToBuy.nStr = 35;
            weaponToBuy.nDex = 18;
            weaponToBuy.nInt = 35;
            weaponToBuy.nEnd = 25;
            weaponToBuy.nFth = 35;
            weaponToBuy.nCost = 2000;
            strcpy(weaponToBuy.weapon, "Roger's Rapier");
            cost = 2000;
            break;
        
        case '3':
            weaponToBuy.nHp = 20;
            weaponToBuy.nStr = 40;
            weaponToBuy.nDex = 21;
            weaponToBuy.nInt = 40;
            weaponToBuy.nEnd = 35;
            weaponToBuy.nFth = 40;
            weaponToBuy.nCost = 4000;
            strcpy(weaponToBuy.weapon, "Coded Sword");
            cost = 4000;
            break;

        case '4':
            weaponToBuy.nHp = 30;
            weaponToBuy.nStr = 55;
            weaponToBuy.nDex = 25;
            weaponToBuy.nInt = 55;
            weaponToBuy.nEnd = 45;
            weaponToBuy.nFth = 55;
            weaponToBuy.nCost = 8000;
            strcpy(weaponToBuy.weapon, "Sword of Night And Flame");
            cost = 8000;
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

void sellEquipment(Player* player) {
    int i;
           printf("\nINVENTORY\n");
        for (i = 0; i < player->inventorySize; i++) {
            printf("[%d] %s - HP: %d, STR: %d, DEX: %d, INT: %d, END: %d, FTH: %d\n",
                   i + 1, player->inventory[i].weapon, player->inventory[i].nHp,
                   player->inventory[i].nStr, player->inventory[i].nDex, player->inventory[i].nInt,
                   player->inventory[i].nEnd, player->inventory[i].nFth);
        }

    printf("\nSelect item to sell (1-%d, 0 to cancel): ", player->inventorySize);
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > player->inventorySize) {
        if (choice != 0) {
            printf("Invalid choice.\n");
        }
        return;
    }

    // Adjust index for zero-based array
    choice -= 1;
    Weapon* w = &player->inventory[choice];
    int sellPrice = w->nCost / 2;  // Selling price is half of the cost

    printf("Selling %s for %d.\n", w->weapon, sellPrice);

    // Increase player's currency
    player->runes += sellPrice;

    // Remove item from inventory
    for (int i = choice; i < player->inventorySize - 1; i++) {
        player->inventory[i] = player->inventory[i + 1];
    }
    player->inventorySize--;

    // Optionally, you could shrink the inventory array if it's no longer needed
    // player->inventory = realloc(player->inventory, player->inventorySize * sizeof(Weapon));

    printf("Item sold.\n");
}

void processShop(Player* player)
{
    char cChoice;
    printf("\n\tSHOP\n");

    printf("Category:\n");
    printf("[1]: Swords\n");
    printf("[2]: Katanas\n");
    printf("[3]: Whips\n");
    printf("[4]: GreatSwords\n");
    printf("[5]: Staves\n");
    printf("[6]: Seals\n");
    printf("[7]: Sell\n");
    printf("[0]: Back\n");

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
    case '7':
         sellEquipment(player);
         break;
    

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