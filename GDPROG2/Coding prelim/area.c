/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *               THE BASIC GAME LOOP               *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "area.h"
#define MAX_BOX 100

void runArea() {
    char nInput = -1;
    int box = 0;
    int position = 0;
    int arr[MAX_BOX];
    int i;
    int enemy;
	int holder=1;
    
    printf("Enter number of boxes: ");
    scanf("%d", &box);
    printf("Enter enemy location: ");
    scanf("%d", &enemy);
    
    for (i = 0; i < box; i++) {
        arr[i] = 0; 
    }

    do {
        arr[enemy] = 9;
        arr[position] = holder; 
        displayArea();
        displayAreaBoard(arr, box, position,enemy);
        printf("Move direction (a: left, d: right, 0: quit): ");
        scanf(" %c", &nInput);
        arr[position] = 0; 
        processAreaInput(nInput, &position, box);
			if (position==enemy)
			{
				holder=0;
			}
			
    } while (nInput != '0');
}

void displayArea() {
    printf("\n");
    printf("\t╔════════════════════╗\n");
    printf("\t│        AREA        │\n");
    printf("\t╚════════════════════╝\n");
    printf("\t[PLAYER] : ♥ ♥ ♥\n");
    printf("\n");
}

void displayAreaBoard(int *arr, int box, int position, int enemy) 
{ 
    int i;
    for (i = 0; i < box; i++) {
        if (i == position) {
            printf("\033[0;35m"); // Set color to violet
            printf("┌───┐\n");
            printf("│ %d │\n", arr[i]); // Display player position
            printf("└───┘\n");
            printf("\033[0m"); // Reset color
        } else if (i == enemy) {
            printf("\033[0;31m"); // Set color to red for enemy
            printf("┌───┐\n");
            printf("│ %d │\n", arr[i]); // Display enemy position
            printf("└───┘\n");
            printf("\033[0m"); // Reset color
        } else {
            printf("┌───┐\n");
            printf("│ %d │\n", arr[i]);
            printf("└───┘\n");
        }
    }
}

void processAreaInput(char nInput, int *position, int box) {
    printf("\t[INPUT] : %c\n", nInput);

    switch (nInput) {
        case 'a':
            if (*position > 0) {
                (*position)--;
            }
            break;
        case 'd':
            if (*position < box - 1) {
                (*position)++;
            }
            break;
    }
}
