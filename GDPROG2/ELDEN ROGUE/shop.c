#include "shop.h"

void buyKatanas(Player* player)
{
    char cChoice;
    int cost;
    char trash;
    Weapon weaponToBuy;

      // Display available katanas
    printf("\nAvailable katanas:\n");
    printf("1. Uchigatana - HP: 20, STR: 30, DEX:15, INT:0 END:35, FTH:0 Cost: 1875\n");
    printf("2. Moonveil - HP: 30, STR: 45, DEX:20, INT:0, END:40, FTH:0 Cost: 3750\n");
    printf("3. Rivers of Blood - HP: 40, STR: 60, DEX:25, INT:0, END:45, FTH:0  Cost: 7500\n");
    printf("4. Sword of Night And Flame - HP: 50, STR:75 DEX: 30, INT:0, END:50, FTH:0 Cost: 15000\n");

        printf("Enter the number of the sword you want to buy: ");
    scanf(" %c", &cChoice);

    switch (cChoice) {
        case '1':
            weaponToBuy.nHp = 20;
            weaponToBuy.nStr = 30;
            weaponToBuy.nDex = 15;
            weaponToBuy.nInt = 0;
            weaponToBuy.nEnd = 35;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 1875;
            strcpy(weaponToBuy.weapon, "Uchigatana");
            cost = 1875;
            break;
        case '2':
            weaponToBuy.nHp = 30;
            weaponToBuy.nStr = 45;
            weaponToBuy.nDex = 20;
            weaponToBuy.nInt = 0;
            weaponToBuy.nEnd = 40;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 3750;
            strcpy(weaponToBuy.weapon, "Moonveil");
            cost = 3750;
            break;
        
        case '3':
            weaponToBuy.nHp = 40;
            weaponToBuy.nStr = 60;
            weaponToBuy.nDex = 25;
            weaponToBuy.nInt = 0;
            weaponToBuy.nEnd = 45;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 7500;
            strcpy(weaponToBuy.weapon, "RIvers of Blood");
            cost = 7500;
            break;

        case '4':
            weaponToBuy.nHp = 50;
            weaponToBuy.nStr = 75;
            weaponToBuy.nDex = 30;
            weaponToBuy.nInt = 0;
            weaponToBuy.nEnd = 50;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 15000;
            strcpy(weaponToBuy.weapon, "Hand of Malenia");
            cost = 15000;
            break;

        default:
            printf("Invalid choice\n");
            printf("Enter any key to continue");
            scanf(" %c",&trash);
            return;
    }

    if (player->runes < cost) {
        printf("\nNot enough runes to buy this weapon.\n");
        printf("\nEnter any key to continue:\n ");
        scanf(" %c",&trash);

        return;
    }

    player->runes -= cost;



    player->inventory[player->inventorySize++] = weaponToBuy;
    printf("You have bought a %s\n", weaponToBuy.weapon);
}

void BuySwords(Player* player)
{
    char cChoice;
    int cost;
    Weapon weaponToBuy;

    // Display available swords
    printf("\nAvailable Swords:\n");
    printf("1. Short Sword - HP: 0, STR: 15, DEX:13, INT:15 END:15, FTH:15 Cost: 100\n");
    printf("2. Roger's Raper - HP: 10, STR: 35, DEX:18, INT:35, END:25, FTH:35 Cost: 2000\n");
    printf("3.Coded Sword - HP: 20, STR: 40, DEX:21, INT:40, END:35, FTH:40  Cost: 4000\n");
    printf("4. Sword of Night And Flame - HP: 30, STR:55 DEX: 25, INT:55, END:45, FTH:55 Cost: 8000\n");

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
            strcpy(weaponToBuy.weapon, "Roger's Raper");
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
            strcpy(weaponToBuy.weapon, "Coded Sword");
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
    printf("[1]Swords\n");
    printf("[2]Katanas\n");
    printf("[3]Whips\n");
    printf("[4]GreatSwords\n");
    printf("[5]Staves\n");
    printf("[6]Seals\n");
    printf("[7]Sell\n");
    printf("[0]Back\n");

    printf("INPUT:");
    scanf(" %c",&cChoice);

    switch (cChoice)
    {
    case '1':
        BuySwords(player);
        break;
    case '2':
        buyKatanas(player);
        break;
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