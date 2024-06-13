#include "inventory.h"
#include "monster.h"
#include "shop.h"
#include <stdio.h>

void displayGhostItem() {
    printf("you got GHOST!!\n");
}

void displayAlienItem() {
    printf("you got ALIEN!!\n");
}

void displaySquidItem() {
    printf("you got SQUID!!\n");
}

void displayInventory(int items[row][col], int selectedRow, int selectedCol) {
    printf("Inventory:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == selectedRow && j == selectedCol) {
                printf("╔═══╗ ");
            } else {
                printf("║ %d ║ ", items[i][j]);
            }
        }
        printf("\n");
        if (i < row - 1) {
            printf("╚═══╝ ");
        }
    }
}


void navigateInventory(int items[row][col]) {
    //important CANNOT ERASE THE SAME PLACE;
    int selectedRow = 0, selectedCol = 0;
    char cInput;
    int i,j;
    int startCol = 0;
    printf("Use W/A/S/D to navigate and X to delete. Press Q to exit.\n");

    while (1) {
       displayInventory(items, selectedRow, selectedCol);
        printf("Selected: [%d][%d]\n", selectedRow, selectedCol);
        scanf(" %c", &cInput);

        if (cInput == 'Q') break;

        switch (cInput) {
            case 'W':
                if (selectedRow > 0) {
                    selectedRow--;
                }
                break;
            case 'S':
                if (selectedRow < row - 1) {
                    selectedRow++;
                }
                break;
            case 'A':
                if (selectedCol > 0) {
                    selectedCol--;
                }
                break;
            case 'D':
                if (selectedCol < col - 1) {
                    selectedCol++;
                }
                break;
            case 'X':
                if (items[selectedRow][selectedCol] != 0) {
                    
                    if (selectedRow == selectedRow) {
                        startCol = selectedCol;
                    }

                    for ( i = selectedRow; i < row; i++) {
                        for ( j = startCol; j < col - 1; j++) {
                            items[i][j] = items[i][j + 1];
                        }
                        if (i < row - 1) {
                            items[i][col - 1] = items[i + 1][0];
                        } else {
                            items[i][col - 1] = 0;
                        }
                    }
                }
                break;
        }
    }
}
