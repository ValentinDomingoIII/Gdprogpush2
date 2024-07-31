#include "shop.h"

void buySeals(Player* player)
{
    char cChoice;
    int cost;
    Weapon weaponToBuy;

    // Display available Seals
    printf("\nAvailable Seals:\n");
    printf("1. Finger Seal - HP: 10, END: 45, \x1b[38;5;124m DEX: 10 \x1b[0m, STR: 0, INT: 15, \x1b[38;5;82m FTH: 20 \x1b[0m Cost: 2500\n");
    printf("2. Godslayer's Seal - HP: 15, END: 50, \x1b[38;5;124m DEX: 12 \x1b[0m, STR: 0, INT: 35, \x1b[38;5;82m FTH: 40 \x1b[0m Cost: 5000\n");
    printf("3. Golden Order Seal - HP: 20, END: 55, \x1b[38;5;124m DEX: 14 \x1b[0m, STR: 0, INT: 65, \x1b[38;5;82m FTH: 65 \x1b[0m Cost: 10000\n");
    printf("4. Dragon Communion Seal - HP: 25, END: 60, \x1b[38;5;124m DEX: 18 \x1b[0m, STR: 0, INT: 75, \x1b[38;5;82m FTH: 80 \x1b[0m Cost: 24000\n");

    printf("Enter the number of the seal you want to buy: ");
    scanf(" %c", &cChoice);

    switch (cChoice) {
        case '1':
            weaponToBuy.nHp = 10;
            weaponToBuy.nEnd = 45;
            weaponToBuy.nDex = 10;
            weaponToBuy.nStr = 0;
            weaponToBuy.nInt = 15;
            weaponToBuy.nFth = 20;
            weaponToBuy.nCost = 2500;
            strcpy(weaponToBuy.weapon, "Finger Seal");
            cost = 2500;
            break;
        case '2':
            weaponToBuy.nHp = 15;
            weaponToBuy.nEnd = 50;
            weaponToBuy.nDex = 12;
            weaponToBuy.nStr = 0;
            weaponToBuy.nInt = 35;
            weaponToBuy.nFth = 40;
            weaponToBuy.nCost = 5000;
            strcpy(weaponToBuy.weapon, "Godslayer's Seal");
            cost = 5000;
            break;
        case '3':
            weaponToBuy.nHp = 20;
            weaponToBuy.nEnd = 55;
            weaponToBuy.nDex = 14;
            weaponToBuy.nStr = 0;
            weaponToBuy.nInt = 65;
            weaponToBuy.nFth = 65;
            weaponToBuy.nCost = 10000;
            strcpy(weaponToBuy.weapon, "Golden Order Seal");
            cost = 10000;
            break;
        case '4':
            weaponToBuy.nHp = 25;
            weaponToBuy.nEnd = 60;
            weaponToBuy.nDex = 18;
            weaponToBuy.nStr = 0;
            weaponToBuy.nInt = 75;
            weaponToBuy.nFth = 80;
            weaponToBuy.nCost = 24000;
            strcpy(weaponToBuy.weapon, "Dragon Communion Seal");
            cost = 24000;
            break;
        default:
            printf("Invalid choice\n");
            return;
    }

    if (player->runes < cost) {
        printf("Not enough runes to buy this seal.\n");
        return;
    }

    player->runes -= cost;
    player->inventory[player->inventorySize++] = weaponToBuy;
    printf("You have bought a %s\n", weaponToBuy.weapon);
}



void buyStaves(Player* player)
{
    char cChoice;
    int cost;
    Weapon weaponToBuy;

    // Display available Staves
    printf("\nAvailable Staves:\n");
    printf("1. Astrologer's Staff - HP: 5, END: 20, \x1b[38;5;124m DEX: 12 \x1b[0m, \x1b[38;5;82m INT: 25 \x1b[0m, STR: 5, FTH: 15 Cost: 2000\n");
    printf("2. Albinauric Staff - HP: 10, END: 30, \x1b[38;5;124m DEX: 14 \x1b[0m, \x1b[38;5;82m INT: 45 \x1b[0m, STR: 10, FTH: 35 Cost: 4000\n");
    printf("3. Staff of the Guilty - HP: 15, END: 40, \x1b[38;5;124m DEX: 16 \x1b[0m, \x1b[38;5;82m INT: 60 \x1b[0m, STR: 15, FTH: 60 Cost: 8000\n");
    printf("4. Carian Regal Scepter - HP: 25, END: 50, \x1b[38;5;124m DEX: 18 \x1b[0m, \x1b[38;5;82m INT: 85 \x1b[0m, STR: 20, FTH: 75 Cost: 16000\n");

    printf("Enter the number of the staff you want to buy: ");
    scanf(" %c", &cChoice);

    switch (cChoice) {
        case '1':
            weaponToBuy.nHp = 5;
            weaponToBuy.nEnd = 20;
            weaponToBuy.nDex = 12;
            weaponToBuy.nStr = 5;
            weaponToBuy.nInt = 25;
            weaponToBuy.nFth = 15;
            weaponToBuy.nCost = 2000;
            strcpy(weaponToBuy.weapon, "Astrologer's Staff");
            cost = 2000;
            break;
        case '2':
            weaponToBuy.nHp = 10;
            weaponToBuy.nEnd = 30;
            weaponToBuy.nDex = 14;
            weaponToBuy.nStr = 10;
            weaponToBuy.nInt = 45;
            weaponToBuy.nFth = 35;
            weaponToBuy.nCost = 4000;
            strcpy(weaponToBuy.weapon, "Albinauric Staff");
            cost = 4000;
            break;
        case '3':
            weaponToBuy.nHp = 15;
            weaponToBuy.nEnd = 40;
            weaponToBuy.nDex = 16;
            weaponToBuy.nStr = 15;
            weaponToBuy.nInt = 60;
            weaponToBuy.nFth = 60;
            weaponToBuy.nCost = 8000;
            strcpy(weaponToBuy.weapon, "Staff of the Guilty");
            cost = 8000;
            break;
        case '4':
            weaponToBuy.nHp = 25;
            weaponToBuy.nEnd = 50;
            weaponToBuy.nDex = 18;
            weaponToBuy.nStr = 20;
            weaponToBuy.nInt = 85;
            weaponToBuy.nFth = 75;
            weaponToBuy.nCost = 16000;
            strcpy(weaponToBuy.weapon, "Carian Regal Scepter");
            cost = 16000;
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






void buyGreatSwords(Player* player)
{
    char cChoice;
    int cost;
    Weapon weaponToBuy;

    // Display available Great Swords
    printf("\nAvailable Great Swords:\n");
    printf("1. Claymore - HP: 15, END: 10, \x1b[38;5;124m DEX: 9 \x1b[0m, \x1b[38;5;82m STR: 20 \x1b[0m, INT: 0, FTH: 0 Cost: 3000\n");
    printf("2. Starscourge Greatsword - HP: 20, END: 15, \x1b[38;5;124m DEX: 14 \x1b[0m, \x1b[38;5;82m STR: 40 \x1b[0m, INT: 0, FTH: 20 Cost: 6000\n");
    printf("3. Inseperable Swords - HP: 25, END: 20, \x1b[38;5;124m DEX: 19 \x1b[0m, \x1b[38;5;82m STR: 70 \x1b[0m, INT: 60, FTH: 60 Cost: 12000\n");
    printf("4. Maliketh's Black Blade - HP: 30, END: 25, \x1b[38;5;124m DEX: 24 \x1b[0m, \x1b[38;5;82m STR: 80 \x1b[0m, INT: 40, FTH: 60 Cost: 24000\n");

    printf("Enter the number of the great sword you want to buy: ");
    scanf(" %c", &cChoice);

    switch (cChoice) {
        case '1':
            weaponToBuy.nHp = 15;
            weaponToBuy.nEnd = 10;
            weaponToBuy.nDex = 9;
            weaponToBuy.nStr = 20;
            weaponToBuy.nInt = 0;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 3000;
            strcpy(weaponToBuy.weapon, "Claymore");
            cost = 3000;
            break;
        case '2':
            weaponToBuy.nHp = 20;
            weaponToBuy.nEnd = 15;
            weaponToBuy.nDex = 14;
            weaponToBuy.nStr = 40;
            weaponToBuy.nInt = 0;
            weaponToBuy.nFth = 20;
            weaponToBuy.nCost = 6000;
            strcpy(weaponToBuy.weapon, "Starscourge Greatsword");
            cost = 6000;
            break;
        case '3':
            weaponToBuy.nHp = 25;
            weaponToBuy.nEnd = 20;
            weaponToBuy.nDex = 19;
            weaponToBuy.nStr = 70;
            weaponToBuy.nInt = 60;
            weaponToBuy.nFth = 60;
            weaponToBuy.nCost = 12000;
            strcpy(weaponToBuy.weapon, "Inseperable Swords");
            cost = 12000;
            break;
        case '4':
            weaponToBuy.nHp = 30;
            weaponToBuy.nEnd = 25;
            weaponToBuy.nDex = 24;
            weaponToBuy.nStr = 80;
            weaponToBuy.nInt = 40;
            weaponToBuy.nFth = 60;
            weaponToBuy.nCost = 24000;
            strcpy(weaponToBuy.weapon, "Maliketh's Black Blade");
            cost = 24000;
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

void buyWhips(Player* player)
{
    char cChoice;
    int cost;
    Weapon weaponToBuy;

    // Display available whips
    printf("\nAvailable Whips:\n");
    printf("1. Whip - HP: 15, END: 60, \x1b[38;5;124m DEX:20 \x1b[0m, STR: 20, INT:0, FTH:0 Cost: 1500\n");
    printf("2. Urumi - HP: 20, END: 70, DEX:25, STR: 40, INT:10, FTH:0 Cost: 3000\n");
    printf("3. Thorned Whip - HP: 30, END: 80, DEX:30, STR: 50, INT:0, FTH:40  Cost: 5000\n");
    printf("4. Hoslow's Petal Whip - HP: 35, END: 90, DEX: 35, STR:55, INT:20, FTH:20 Cost: 10000\n");

    printf("Enter the number of the whip you want to buy: ");
    scanf(" %c", &cChoice);

    switch (cChoice) {
        case '1':
            weaponToBuy.nHp = 15;
            weaponToBuy.nStr = 20;
            weaponToBuy.nDex = 20;
            weaponToBuy.nInt = 0;
            weaponToBuy.nEnd = 60;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 1500;
            strcpy(weaponToBuy.weapon, "Whip");
            cost = 1500;
            break;
        case '2':
            weaponToBuy.nHp = 20;
            weaponToBuy.nStr = 40;
            weaponToBuy.nDex = 25;
            weaponToBuy.nInt = 10;
            weaponToBuy.nEnd = 70;
            weaponToBuy.nFth = 0;
            weaponToBuy.nCost = 3000;
            strcpy(weaponToBuy.weapon, "Urumi");
            cost = 3000;
            break;
        case '3':
            weaponToBuy.nHp = 30;
            weaponToBuy.nStr = 50;
            weaponToBuy.nDex = 30;
            weaponToBuy.nInt = 0;
            weaponToBuy.nEnd = 80;
            weaponToBuy.nFth = 40;
            weaponToBuy.nCost = 5000;
            strcpy(weaponToBuy.weapon, "Thorned Whip");
            cost = 5000;
            break;
        case '4':
            weaponToBuy.nHp = 35;
            weaponToBuy.nStr = 55;
            weaponToBuy.nDex = 35;
            weaponToBuy.nInt = 20;
            weaponToBuy.nEnd = 90;
            weaponToBuy.nFth = 20;
            weaponToBuy.nCost = 10000;
            strcpy(weaponToBuy.weapon, "Hoslow's Petal Whip");
            cost = 10000;
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

void buyKatanas(Player* player)
{
    char cChoice;
    int cost;
    char trash;
    Weapon weaponToBuy;

    // Display available katanas
    printf("\nAvailable Katanas:\n");
    printf("1. Uchigatana - \x1b[38;5;82m HP: 20 \x1b[0m, END: 35, \x1b[38;5;124m DEX: 15 \x1b[0m, STR: 30, INT: 0, FTH: 0 Cost: 1875\n");
    printf("2. Moonveil - \x1b[38;5;82m HP: 30 \x1b[0m, END: 40, \x1b[38;5;124m DEX: 20 \x1b[0m, STR: 45, INT: 0, FTH: 0 Cost: 3750\n");
    printf("3. Rivers of Blood - \x1b[38;5;82m HP: 40 \x1b[0m, END: 45, \x1b[38;5;124m DEX: 25 \x1b[0m, STR: 60, INT: 0, FTH: 0 Cost: 7500\n");
    printf("4. Sword of Night And Flame - \x1b[38;5;82m HP: 50 \x1b[0m, END: 50, \x1b[38;5;124m DEX: 30 \x1b[0m, STR: 75, INT: 0, FTH: 0 Cost: 15000\n");

    printf("Enter the number of the katana you want to buy: ");
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
            strcpy(weaponToBuy.weapon, "Rivers of Blood");
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
            strcpy(weaponToBuy.weapon, "Sword of Night and Flame");
            cost = 15000;
            break;
        default:
            printf("Invalid choice\n");
            printf("Enter any key to continue");
            scanf(" %c", &trash);
            return;
    }

    if (player->runes < cost) {
        printf("Not enough runes to buy this weapon.\n");
        printf("Enter any key to continue: ");
        scanf(" %c", &trash);
        return;
    }

    player->runes -= cost;
    player->inventory[player->inventorySize++] = weaponToBuy;
    printf("You have bought a %s\n", weaponToBuy.weapon);
}


void buySwords(Player* player)
{
    char cChoice;
    int cost;
    Weapon weaponToBuy;

    // Display available swords
    printf("\nAvailable Swords:\n");
    printf("1. Short Sword - HP: 0, END: 15, \x1b[38;5;124m DEX: 13 \x1b[0m, STR: 15, INT: 15, FTH: 15 Cost: 100\n");
    printf("2. Roger's Raper - HP: 10, END: 25, \x1b[38;5;124m DEX: 18 \x1b[0m, STR: 35, INT: 35, FTH: 35 Cost: 2000\n");
    printf("3. Coded Sword - HP: 20, END: 35, \x1b[38;5;124m DEX: 21 \x1b[0m, STR: 40, INT: 40, FTH: 40 Cost: 4000\n");
    printf("4. Sword of Night And Flame - HP: 30, END: 45, \x1b[38;5;124m DEX: 25 \x1b[0m, STR: 55, INT: 55, FTH: 55 Cost: 8000\n");

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
        buySwords(player);
        break;
    case '2':
        buyKatanas(player);
        break;
    case '3':
        buyWhips(player);
    case '4':
        buyGreatSwords(player);
        break;
    case '5':
        buyStaves(player);
        break;
    case '6':
        buySeals(player);
        break;
    case '7':
         sellEquipment(player);
         break;
    

    default:
        break;
    }

}