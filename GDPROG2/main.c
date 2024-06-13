#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void displayInventory(int inventory[ROWS][COLS]) {
    printf("\nInventory:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (inventory[i][j] == 0) {
                printf("[ ] ");
            } else {
                printf("[%d] ", inventory[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void addItem(int inventory[ROWS][COLS], int item) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (inventory[i][j] == 0) {
                inventory[i][j] = item;
                return;
            }
        }
    }
    printf("Inventory is full!\n");
}

void deleteItem(int inventory[ROWS][COLS], int item) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (inventory[i][j] == item) {
                inventory[i][j] = 0;
                return;
            }
        }
    }
    printf("Item not found in inventory!\n");
}

int main() {
    int inventory[ROWS][COLS] = {0};
    char input;
    int item;

    while (1) {
        printf("Enter command (e: add item, i: check inventory, d: delete item, q: quit): ");
        scanf(" %c", &input);

        switch (input) {
            case 'e':
                printf("Enter item to add (1-3): ");
                scanf("%d", &item);
                if (item < 1 || item > 3) {
                    printf("Invalid item! Choose between 1-3.\n");
                } else {
                    addItem(inventory, item);
                }
                break;
            case 'i':
                displayInventory(inventory);
                break;
            case 'd':
                printf("Enter item to delete: ");
                scanf("%d", &item);
                deleteItem(inventory, item);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command!\n");
        }
    }

    return 0;
}
