#include "inventory.h"
#include "monster.h"
#include "shop.h"

void displayInventory(int aItems[row][col], int nSelectedRow, int nSelectedCol) {
    printf("   ► INVENTORY ───────\n\n     ");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == nSelectedRow && j == nSelectedCol) {
                processSelectBoxColor1(aItems,i,j);
            } else {
                processNormBoxColor1(aItems,i,j);
            }
        }
        printf("\n     ");

        for (int j = 0; j < col; j++) {
            if (i == nSelectedRow && j == nSelectedCol) 
                processSelectBoxColor2(aItems,i,j);
            else {
                processNormBoxColor2(aItems,i,j);
            }
        }
        printf("\n     ");

        for (int j = 0; j < col; j++) {
            if (i == nSelectedRow && j == nSelectedCol) {
                processSelectBoxColor3(aItems,i,j);
            } else {
                processNormBoxColor3(aItems,i,j);
            }
        }
        
        printf("\n     ");
    }

    printf("\n   ───────────────────\n");
    printf("   [INPUT]  : ");
}

void navigateInventory(int aItems[row][col]) {
    int nSelectedRow = 0, nSelectedCol = 0;
    char cInput;
    int i, j;
    int startCol = 0;
    //printf("Use W/A/S/D to navigate and X to delete. Press Q to exit.\n");
    printf("\n");

    while (1) {
        displayInventory(aItems, nSelectedRow, nSelectedCol);
        //printf("Selected: [%d][%d]\n", selectedRow, selectedCol);
        scanf(" %c", &cInput);
        printf("\n");

        if (cInput == 'Q') break;

        if (cInput == 'W') {
            if (nSelectedRow > 0) {
                nSelectedRow--;
            }
        } else if (cInput == 'S') {
            if (nSelectedRow < row - 1) {
                nSelectedRow++;
            }
        } else if (cInput == 'A') {
            if (nSelectedCol > 0) {
                nSelectedCol--;
            }
        } else if (cInput == 'D') {
            if (nSelectedCol < col - 1) {
                nSelectedCol++;
            }
        } else if (cInput == 'E') {
            if (aItems[nSelectedRow][nSelectedCol] != 0) {
                startCol = nSelectedCol;

                for (i = nSelectedRow; i < row; i++) {
                    for (j = startCol; j < col - 1; j++) {
                        aItems[i][j] = aItems[i][j + 1];
                    }
                    if (i < row - 1) {
                        aItems[i][col - 1] = aItems[i + 1][0];
                    } else {
                        aItems[i][col - 1] = 0;
                    }
                }
            }
        }
    }
}

void processSelectBoxColor1(int* pItems, int nX, int nY){ 
    if(*((pItems + nX * row) + nY) == 0)
        printf("╔═══╗ ");
        else if(*((pItems + nX * row) + nY) == 1){
                ghostFG();
                printf("╔═══╗ ");
                reset();
        }
            else if(*((pItems + nX * row) + nY) == 2){
                alienFG();
                printf("╔═══╗ ");
                reset();
            }
                else if(*((pItems + nX * row) + nY) == 3){
                    squidFG();
                    printf("╔═══╗ ");
                    reset();
                }
}

void processSelectBoxColor2(int* pItems, int nX, int nY){ 
    if(*((pItems + nX * row) + nY) == 0)
        printf("║   ║ ");
        else if(*((pItems + nX * row) + nY) == 1){
                ghostFG();
                printf("║█▀█║ ");
                reset();
        }
            else if(*((pItems + nX * row) + nY) == 2){
                alienFG();
                printf("║▀▄▀║ ");
                reset();
            }
                else if(*((pItems + nX * row) + nY) == 3){
                    squidFG();
                    printf("║▄█▄║ ");
                    reset();
                }
}

void processSelectBoxColor3(int* pItems, int nX, int nY){ 
    if(*((pItems + nX * row) + nY) == 0)
        printf("╚═══╝ ");
        else if(*((pItems + nX * row) + nY) == 1){
                ghostFG();
                printf("╚═══╝ ");
                reset();
        }
            else if(*((pItems + nX * row) + nY) == 2){
                alienFG();
                printf("╚═══╝ ");
                reset();
            }
                else if(*((pItems + nX * row) + nY) == 3){
                    squidFG();
                    printf("╚═══╝ ");
                    reset();
                }
}

void processNormBoxColor1(int* pItems, int nX, int nY){ 
    if(*((pItems + nX * row) + nY) == 0)
        printf("┌───┐ ");
        else if(*((pItems + nX * row) + nY) == 1){
                ghostFG();
                printf("┌───┐ ");
                reset();
        }
            else if(*((pItems + nX * row) + nY) == 2){
                alienFG();
                printf("┌───┐ ");
                reset();
            }
                else if(*((pItems + nX * row) + nY) == 3){
                    squidFG();
                    printf("┌───┐ ");
                    reset();
                }
}

void processNormBoxColor2(int* pItems, int nX, int nY){ 
    if(*((pItems + nX * row) + nY) == 0)
        printf("│   │ ");
        else if(*((pItems + nX * row) + nY) == 1){
                ghostFG();
                printf("│█▀█│ ");
                reset();
        }
            else if(*((pItems + nX * row) + nY) == 2){
                alienFG();
                printf("│▀▄▀│ ");
                reset();
            }
                else if(*((pItems + nX * row) + nY) == 3){
                    squidFG();
                    printf("│▄█▄│ ");
                    reset();
                }
}

void processNormBoxColor3(int* pItems, int nX, int nY){ 
    if(*((pItems + nX * row) + nY) == 0)
        printf("└───┘ ");
        else if(*((pItems + nX * row) + nY) == 1){
                ghostFG();
                printf("└───┘ ");
                reset();
        }
            else if(*((pItems + nX * row) + nY) == 2){
                alienFG();
                printf("└───┘ ");
                reset();
            }
                else if(*((pItems + nX * row) + nY) == 3){
                    squidFG();
                    printf("└───┘ ");
                    reset();
                }
}