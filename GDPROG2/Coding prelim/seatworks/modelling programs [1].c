#include <stdio.h>
#include "inventory.c" // Include the inventory header file
#include "enemy.c."

#define MAX_BOXES 7
#define INVENTORY_SIZE 10

// Function declarations
void runArea();
void displayArea();
void displayAreaBoard(char *arr, int nPosition);
void processAreaInput(char cInput, int *nPosition, int *inventory, int *inventorySize, int *lives);

int main() {
    runArea();
    return 0;
}

void runArea() {
    char cInput;
    int nPosition = 0; // Initialize player position
    char arr[MAX_BOXES];
    int inventory[INVENTORY_SIZE] = {0}; // Initialize inventory
    int inventorySize = 0; // Current inventory size
    int i;
    int lives=3;
    // Initialize the array
    for (i = 0; i < MAX_BOXES; i++) {
        arr[i] = ' ';
    }

    do {
        // Update the array with the player's position
        arr[nPosition] = '■';

        displayArea();
        displayAreaBoard(arr, nPosition);

        // Reset the player's position in the array to empty space
        arr[nPosition] = ' ';

        printf("Enter input (a: left, d: right, e: interact, i: inventory, 0: quit): ");
        scanf(" %c", &cInput); // Space before %c to consume any newline character

        // Process input to update the player's position and interact with items
        processAreaInput(cInput, &nPosition, inventory, &inventorySize,&lives);

    } while (cInput != '0' && lives>0 );
            if(lives<=0)
            {
                displayGameover();
            }
}

void displayArea() {
    printf("\n");
    printf("\t╔════════════════════╗\n");
    printf("\t│        AREA        │\n");
    printf("\t╚════════════════════╝\n");
    printf("\t[PLAYER] : ♥ ♥ ♥\n");
    printf("\n");
}

void displayAreaBoard(char *arr, int nPosition) {
    int i;

    // Print top part of all boxes
    printf("\t");
    for (i = 0; i < MAX_BOXES; i++) {
        if (i == nPosition) {
            printf("\033[0;35m"); // Set color to violet for player
            printf("\t╔═══╗ ");
            printf("\033[0m"); // Reset color
        } else if (i == 3) { // Item at box 4
            printf("\t┌┬┬┬┐ ");
        } else if (i == 5) { // Enemy at box 6
            printf("\t┌───┐ ");
        } else {
            printf("\t┌───┐ ");
        }
    }
    printf("\n\t");

    // Print middle part of all boxes
    for (i = 0; i < MAX_BOXES; i++) {
        if (i == nPosition) {
            printf("\033[0;35m"); // Set color to violet for player
            printf("\t║ ■ ║");
            printf("\033[0m"); // Reset color
        } else if (i == 3) { // Item at box 4
            printf("\t│││││");
        } else if (i == 5) { // Enemy at box 6
            printf("\t│ E │");
        } else {
            printf("\t│ %c │", arr[i]);
        }
    }
    printf("\n\t");

    // Print bottom part of all boxes
    for (i = 0; i < MAX_BOXES; i++) {
        if (i == nPosition) {
            printf("\033[0;35m"); // Set color to violet for player
            printf("\t╚═══╝ ");
            printf("\033[0m"); // Reset color
        } else if (i == 3) { // Item at box 4
            printf("\t└┴┴┴┘ ");
        } else if (i == 5) { // Enemy at box 6
            printf("\t└───┘ ");
        } else {
            printf("\t└───┘ ");
        }
    }
    printf("\n");
}

void processAreaInput(char cInput, int *nPosition, int *inventory, int *inventorySize, int *lives) {
    switch (cInput) {
        case 'a':
            if (*nPosition > 0) {
                (*nPosition)--;
            }
            break;
        case 'd':
            if (*nPosition < MAX_BOXES - 1) {
                (*nPosition)++;
            }
            break;
        case 'e':
            if (*nPosition == 3 && *inventorySize < INVENTORY_SIZE) {
                inventory[*inventorySize] = 3; // Add item 3 to inventory
                (*inventorySize)++;
                displayItem();
                break;
            }
            
                if(*nPosition == 5)
                {
                    (*lives)--;
                    displayEnemy();
                }
            break;
        case 'i':
            runInventory(inventory, *inventorySize);
            break;
    }
}




