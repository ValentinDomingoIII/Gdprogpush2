#include "inventory.h" 
#define INVENTORY_SIZE 10

void displayItem();
void runInventory(int *inventory, int inventorySize);
void displayInventory(int *inventory, int inventorySize);

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
    int i;
    printf("\t ┌───────────────┐\n"); 
    printf("\t │   INVENTORY   │\n"); 
    printf("\t ├───────────────┤\n"); 
    printf("\t └───────────────┘\n");

    for (i = 0; i < inventorySize; i++) {
        printf("\t┌───┐");
    }
    printf("\n");
    for (i = 0; i < inventorySize; i++) {
        printf("\t│▄▀▄│");
    
    }
printf("\n");
    for (i = 0; i < inventorySize; i++) {
        printf("\t└───┘ ");
  
    }
  printf("\n");

    
}
