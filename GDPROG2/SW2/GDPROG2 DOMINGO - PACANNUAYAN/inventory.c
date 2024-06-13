#include "inventory.h"
#include "monster.h"
#include "shop.h"

void displayInventory(int items[row][col], int selectedRow, int selectedCol) {
    printf("Inventory:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == selectedRow && j == selectedCol) {
                printf("╔═══╗ ");
            } else {
                
                printf("┌───┐ ");
                
            }
        }
        printf("\n");

        for (int j = 0; j < col; j++) {
            if (i == selectedRow && j == selectedCol) {
                printf("║ ");
                
                printf("%d", items[i][j]);
                
                printf(" ║ ");
            } else {
                
                printf("│ %d │ ", items[i][j]);
                
            }
        }
        printf("\n");

        for (int j = 0; j < col; j++) {
            if (i == selectedRow && j == selectedCol) {
                printf("╚═══╝ ");
            } else {
                
                printf("└───┘ ");
                
            }
        }
        printf("\n");
    }
}

void navigateInventory(int items[row][col]) {
    int selectedRow = 0, selectedCol = 0;
    char cInput;
    int i, j;
    int startCol = 0;
    printf("Use W/A/S/D to navigate and X to delete. Press Q to exit.\n");

    while (1) {
        displayInventory(items, selectedRow, selectedCol);
        printf("Selected: [%d][%d]\n", selectedRow, selectedCol);
        scanf(" %c", &cInput);

        if (cInput == 'Q') break;

        if (cInput == 'W') {
            if (selectedRow > 0) {
                selectedRow--;
            }
        } else if (cInput == 'S') {
            if (selectedRow < row - 1) {
                selectedRow++;
            }
        } else if (cInput == 'A') {
            if (selectedCol > 0) {
                selectedCol--;
            }
        } else if (cInput == 'D') {
            if (selectedCol < col - 1) {
                selectedCol++;
            }
        } else if (cInput == 'X') {
            if (items[selectedRow][selectedCol] != 0) {
                startCol = selectedCol;

                for (i = selectedRow; i < row; i++) {
                    for (j = startCol; j < col - 1; j++) {
                        items[i][j] = items[i][j + 1];
                    }
                    if (i < row - 1) {
                        items[i][col - 1] = items[i + 1][0];
                    } else {
                        items[i][col - 1] = 0;
                    }
                }
            }
        }
    }
}

