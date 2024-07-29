#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int str;
    int hp;
    int faith;
    int dex;
    int intelligence;
    int endurance;
    int cost;
} Weapon;

// Function to print weapon stats
void printWeapon(Weapon *weapon) {
    printf("STR: %d, HP: %d, Faith: %d, DEX: %d, INT: %d, END: %d, Cost: %d\n",
        weapon->str, weapon->hp, weapon->faith, weapon->dex, weapon->intelligence,
        weapon->endurance, weapon->cost);
}

// Function to print the inventory
void printInventory(Weapon *inventory, size_t size) {
    printf("Inventory:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%zu: ", i);
        printWeapon(&inventory[i]);
    }
}

// Function to add a weapon to the inventory
void addWeapon(Weapon **inventory, size_t *size, size_t *capacity, Weapon weapon) {
    if (*size == *capacity) {
        *capacity *= 2;
        *inventory = realloc(*inventory, *capacity * sizeof(Weapon));
        if (*inventory == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    (*inventory)[(*size)++] = weapon;
}

// Function to remove a weapon from the inventory
void removeWeapon(Weapon *inventory, size_t *size, size_t index) {
    if (index < *size) {
        for (size_t i = index; i < *size - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*size)--;
    } else {
        printf("Invalid weapon index\n");
    }
}

int main() {
    // Define the shop with some weapons
    Weapon shop[] = {
        {10, 5, 0, 7, 2, 8, 100},
        {12, 4, 0, 5, 1, 10, 150},
        {2, 1, 10, 3, 12, 4, 200}
    };
    size_t shopSize = sizeof(shop) / sizeof(shop[0]);

    // Initialize the inventory
    Weapon *inventory = malloc(2 * sizeof(Weapon));
    if (inventory == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    size_t inventorySize = 0;
    size_t inventoryCapacity = 2;

    printf("Welcome to the shop!\n");
    printInventory(shop, shopSize);

    int choice;
    size_t index;
    do {
        printf("\n1. Buy weapon\n");
        printf("2. Sell weapon\n");
        printf("3. View inventory\n");
        printf("4. View shop\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the index of the weapon to buy: ");
                scanf("%zu", &index);
                if (index < shopSize) {
                    addWeapon(&inventory, &inventorySize, &inventoryCapacity, shop[index]);
                    printf("Bought weapon %zu\n", index);
                } else {
                    printf("Invalid weapon index\n");
                }
                break;
            case 2:
                printf("Enter the index of the weapon to sell: ");
                scanf("%zu", &index);
                removeWeapon(inventory, &inventorySize, index);
                printf("Sold weapon %zu\n", index);
                break;
            case 3:
                printInventory(inventory, inventorySize);
                break;
            case 4:
                printInventory(shop, shopSize);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    free(inventory);

    return 0;
}
