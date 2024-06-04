#include "inventory.h" 
#define INVENTORY_SIZE 10


void displayItem() {
    printf("\t ┌───────────────┐\n"); 
    printf("\t │ YOU GOT...    │\n"); 
    printf("\t ├───────────────┤\n"); 
    printf("\t │     ╔═══╗     │\n"); 
    printf("\t │     ║▄▀▄║     │\n"); 
    printf("\t │     ╚═══╝     │\n"); 
    printf("\t │    ITEM 03    │\n"); 
    printf("\t ├───────────────┤\n"); 
    printf("\t └───────────────┘\n");
}

void runInventory(int *inventory, int inventorySize) {
    displayInventory(inventory, inventorySize);
}

void displayInventory(int *inventory, int inventorySize) {
    int i,j;
    printf("\t ┌───────────────┐\n"); 
    printf("\t │   INVENTORY   │\n"); 
    printf("\t ├───────────────┤\n"); 
    printf("\t └───────────────┘\n");

    for (i = 0; i < inventorySize; i += 3) {
        // Print the top parts of the boxes
        for (j = i; j < i + 3 && j < inventorySize; j++) {
            printf("\t┌───┐");
        }
        printf("\n");

        // Print the middle parts of the boxes
        for (j = i; j < i + 3 && j < inventorySize; j++) {
            printf("\t│▄▀▄│");
        }
        printf("\n");

        // Print the bottom parts of the boxes
        for (j = i; j < i + 3 && j < inventorySize; j++) {
            printf("\t└───┘");
        }
        printf("\n");
    }
}
